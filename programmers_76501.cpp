#include <string>
#include <vector>

using namespace std;


int solution(vector<int> absolutes, vector<bool> signs) {
    int answer = 0;
    for (int i = 0; i < absolutes.size(); ++i)
        answer += absolutes[i] * (signs[i] ? 1 : -1);    
    return answer;
}

// C++23 의 views::zip 를 활용하여 python의 zip 과 같은 방식으로도 해결 가능
// zip: 같은 크기의 두 컨테이너의 인자들을 결합