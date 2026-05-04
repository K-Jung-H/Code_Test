#include <string>
#include <vector>
#include <cmath>

using namespace std;

// 주어진 수가 완전제곱수인지 판별하고 다음 완전제곱수를 반환하는 함수
//pow() 함수는 실수형(double) 기반의 무거운 연산을 수행하므로 미세한 오차가 발생할 수 있음
// pow(answer, 2) 대신 정수 곱셈인 (answer * answer)를 사용하면 오차 없이 더 빠른 처리가 가능

long long solution(long long n) {
    long long answer = sqrt(n);

    if(pow(answer,2) == n)
        return pow(answer+1, 2);
    else
        return -1;
}