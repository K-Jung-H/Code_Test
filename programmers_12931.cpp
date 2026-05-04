#include <iostream>
#include <string>

using namespace std;

// while 사용 (성능 우선)
// - CPU 레벨에서 가장 빠르고 직접적으로 처리할 수 있는 정수 산술 연산(ALU)을 최대한 활용. 
// - 데이터 구조의 변환이 없고 추가적인 메모리 공간을 요구하지 않음.

int solution(int n)
{
    int answer = n % 10;
    
    while(n /= 10)
    {
        int temp = n % 10;
        answer += temp;
    }

    return answer;
}

// string 해결법 (구현이 더 쉬움)
// - 데이터를 연속된 문자의 나열로 취급하여 조작의 직관성이 높음.
// -  앞자리(왼쪽)부터 순방향으로 읽을 수 있음.
int solution(int n)
{
    int answer = 0;
    
    string text = to_string(n);

    for (const char txt : text)
        answer += txt - '0';

    
    return answer;
}