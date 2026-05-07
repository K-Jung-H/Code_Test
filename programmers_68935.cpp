#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// N진수 변환기
string Change_N(int n, int m) 
{
    if (n < m) return to_string(n);
    
    return Change_N(n / m, m) + to_string(n % m);
}


int solution(int n) {
    string result_0 = Change_N(n, 3);

    reverse(result_0.begin(), result_0.end());

    long long result_1 = stoll(result_0, nullptr, 3);
    return result_1;
}


// Stack을 활용한 해결법
int solution(int n) {
    int answer = 0;
    vector<int> v;
    while(n > 0){
        v.push_back(n%3);
        n/=3;
    }
    int k = 1;
    while(!v.empty()) {
        answer += k*v.back();
        v.pop_back();
        k*=3;
    }

    return answer;
}