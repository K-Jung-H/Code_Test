#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<bool> is_prime(n+1,true);
    is_prime[0] = false;
    is_prime[1] = false;
    
    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
    
    
    return count(is_prime.begin(),is_prime.end(), true);
}