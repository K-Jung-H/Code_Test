#include <string>
#include <vector>

using namespace std;

// O(N) 방식
long long solution(int a, int b) {
    long long answer = 0;

    if(a > b)
        swap(a,b);

    for(int i = a; i <= b; ++i)
        answer += i;

    return answer;
}


// O(1) 방식
// 수학적 접근법: 등차수열의 합
// ((첫 항 + 마지막 항) * 항의 개수) / 2

long long solution(int a, int b) {
    return (long long)(a + b) * (abs(a - b) + 1) / 2;
}