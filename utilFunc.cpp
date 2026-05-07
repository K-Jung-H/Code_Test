#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>

using namespace std;

// N의 약수 개수
int getDivisorsCount(int n) {
    int count = 0;
    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            count += (i * i == n) ? 1 : 2; 
        }
    }
    return count;
}

// N의 약수 리스트
vector<int> getDivisorsList(int n) {
    vector<int> divisors;
    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            divisors.push_back(i);

            if (i * i != n) {
                divisors.push_back(n / i);
            }
        }
    }
    //sort(divisors.begin(), divisors.end());
    return divisors;
}


// A,B 의 최대공약수
// A > B
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

// N진수 변환 함수
string Change_N(int n, int m) 
{
    if (n < m) return to_string(n);
    
    return Change_N(n / m, m) + to_string(n % m);
}

int N_Change(string n, int m)
{
    long long result = 0;

    for (char c : n)
        result = result * m + (c - '0');
    return result;
}

//long long result = stoll(n, nullptr, m);