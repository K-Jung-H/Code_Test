#include <string>
#include <vector>

using namespace std;

int solution(vector<int> a, vector<int> b) {
    int answer = 0;

    for (int i = 0; i < a.size(); ++i)
        answer += a[i] * b[i];
    return answer;
}

// 내적 연산 전용 STL 함수 inner_product
// 두 개의 컨테이너 구간을 동시에 순회하면서, 대응하는 위치에 있는 원소들끼리 곱한 뒤
// 그 결과들을 누적하여 더한 총합을 반환하는 템플릿 함수
#include <numeric>

int solution(vector<int> a, vector<int> b) {
    return inner_product(a.begin(), a.end(), b.begin(), 0);
}