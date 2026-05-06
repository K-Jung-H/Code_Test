#include <string>
#include <vector>

using namespace std;

int getDivisorsCount(int n) {
    int count = 0;
    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            count += (i * i == n) ? 1 : 2; 
        }
    }
    return count;
}

int solution(int left, int right) {
    int answer = 0;

    for (int i = left; i <= right; ++i)
        answer += getDivisorsCount(i) % 2 == 0 ? i : -i;
    
    return answer;
}