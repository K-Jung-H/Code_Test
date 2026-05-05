#include <string>
#include <iostream>
#include <algorithm>
#include <cctype>

using namespace std;

// 초기 답안 
bool solution(string s)
{
    transform(s.begin(), s.end(),s.begin(), ::toupper);

    int p = count(s.begin(), s.end(), 'P');
    int y = count(s.begin(), s.end(), 'Y');
    
    return (p == y);
}


// 안정적인 방법
// toupper 함수의 namespace가 충돌 할 수 있음
// 람다 표현식을 사용하여 컴파일러에게 어떤 함수를 쓸지, 그리고 어떤 타입으로 변환할지 직접 지정하기
bool solution(string s)
{
    auto upper = [](unsigned char c) {return std::toupper(c); };
    transform(s.begin(), s.end(),s.begin(), upper);

    int p = count(s.begin(), s.end(), 'P');
    int y = count(s.begin(), s.end(), 'Y');
    
    return (p == y);
}