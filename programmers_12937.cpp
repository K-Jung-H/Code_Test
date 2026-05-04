#include <string>
#include <vector>

using namespace std;

// 비교 연산
string solution(int num) {
    if(num % 2 == 0) return "Even";
    else return "Odd";
}

// 비트 연산
string solution(int num) {
    return num & 1 ? "Odd" : "Even";
}