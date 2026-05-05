#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int answer = 0;
    long long test_num = num;

    if (test_num == 1)
        return 0;

    while(answer < 500)
    {
        if(test_num == 1)
            return answer;
        else if(test_num % 2 == 0)
            test_num /= 2;
        else
            test_num = test_num * 3 + 1;

        answer +=1;
    }

    return -1;
}

// Clean Code
// 비트 연산자 활용
int solution(int num) {
    int answer = 0;
    long long temp = num;
    
    while (temp != 1 && answer < 500) {
            temp = (temp & 1) ? (temp * 3 + 1) : (temp >> 1);
            answer++;
        }

    return temp == 1 ? answer : -1;
}