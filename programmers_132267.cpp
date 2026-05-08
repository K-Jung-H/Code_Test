#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;

    while (n >= a) {
        int trade = (n / a) * b;
        answer += trade;
        n = (n % a) + trade;
    }

    return answer;
}