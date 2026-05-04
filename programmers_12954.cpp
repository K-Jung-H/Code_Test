#include <string>
#include <vector>

using namespace std;

// 메모리 동적 할당 방식
vector<long long> solution(int x, int n) {
    vector<long long> answer;

    for (int i = 1; i <= n; ++i)
        answer.push_back(x * i);

    return answer;
}

// 메모리 사전 할당 방식
vector<long long> solution(int x, int n) {
    vector<long long> answer(n,x);

    for (int i = 0; i < n; ++i)
        answer[i] = x * (i+1);

    return answer;
}

// 최적 혼합 방식
// reverse를 통해, 메모리 공간을 n만큼 한 번에 확보
vector<long long> solution(int x, int n) {
    vector<long long> answer;  
    answer.reserve(n); 
    for (int i = 1; i <= n; ++i) {
        answer.push_back(x * i);
    }

    return answer;
}