#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 최대공약수를 직접 찾는 방식

#include <iterator>

vector<int> GetM(int n)
{
    vector<int> nList;

    for(int i = 1; i * i <= n; ++i)
    {
        if(n  % i == 0)
        {   
            nList.push_back(i);
            
            if(n/i != i)
                nList.push_back(n/i);
        }
    }

    sort(nList.begin(), nList.end());
    return nList;
}

vector<int> solution(int n, int m) {
    vector<int> answer;
    vector<int> temp;
    vector<int> nListA = GetM(n);
    vector<int> nListB = GetM(m);

    set_intersection(nListA.begin(), nListA.end(), 
                     nListB.begin(), nListB.end(), 
                     back_inserter(temp));

    int A = temp.back();
    int B = (int)(((long long)n * m) / A);

    answer.push_back(A);
    answer.push_back(B);

    return answer;
}

// 최대공약수를 구하는 재귀함수 방식

int custom_gcd(int a, int b) {
    if (b == 0) return a;
    return custom_gcd(b, a % b);
}

vector<int> solution(int n, int m) {
    vector<int> answer;

    int X = max<int>(n,m);
    int Y = min<int>(n,m);
    
    int A = custom_gcd(X, Y);
    int B = (int)(((long long)n * m) / A);

    answer.push_back(A);
    answer.push_back(B);

    return answer;
}

// 최대공약수 공식 함수 사용
#include <numeric>

vector<int> solution(int n, int m) {
    int gcd_val = gcd(n, m);
    int lcm_val = (int)(((long long)n * m) / gcd_val);
    
    return {gcd_val, lcm_val};
}