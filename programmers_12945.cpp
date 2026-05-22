#include <string>
#include <vector>

using namespace std;

// 나머지 연산의 덧셈 성질
// 나머지 연산은 합의 법칙이 성립하기 때문에, 마지막에 한 번 나머지를 구하는 것과 매 단계 나머지를 구해 더하는 것은 결과가 같다.

int solution(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    vector<int> f(n + 1);
    
    f[0] = 0;
    f[1] = 1;
    
    for(int i = 2; i <= n; i++) {
        f[i] = (f[i - 1] + f[i - 2]) % 1234567; 
    }
    
    return f[n];
}