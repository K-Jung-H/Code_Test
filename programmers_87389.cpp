#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int x = 2;

    while(answer == 0)
    {
        if(n % x == 1)
            answer = x;

        ++x;
    }

    return answer;
}


// 논리적 개선안
int solution(int n) {
    for (int x = 2; x < n; ++x) {
        if (n % x == 1) {
            return x;
        }
    }
    
    return -1; 
}