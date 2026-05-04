#include <string>
#include <vector>

using namespace std;

// 숫자 연산 방식
bool solution(int x) {
    int sum = 0;
    int temp = x; 

    while (temp > 0) { 
        sum += temp % 10; 
        temp /= 10;       
    }
        
    return (x % sum == 0); 
}


// 문자열 방식
bool solution(int x) {
    int sum = 0;
    string numList = to_string(x);

    for(const char num : numList)
        sum += num - '0';
    return (x % sum == 0);
}