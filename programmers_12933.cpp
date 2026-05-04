#include <string>
#include <vector>
#include <algorithm>

using namespace std;


// 동적 배열에 담고, 하나의 정수로 재조립(수학 연산 + 벡터 기반 정렬 방식)
// 순수 CPU 산술 연산 위주로 동작하여 이론적 처리 속도는 가장 빠르지만, 
// 자릿수를 분해하고 다시 합치는 로직이 장황하여 버그 발생률이 높고 가독성이 떨어집니다.

long long solution(long long n) {
    long long answer = 0;
    vector<int>numList;

    numList.push_back(n % 10);

    while(n /= 10)
    {
        numList.push_back(n % 10);
    }

    sort(numList.begin(), numList.end(), [](int a, int b) { return a > b; });

    for(const int num : numList)
    {
        answer += num;
        answer *= 10;
    }    
    answer /= 10;
    
    return answer;
}

// 정수 -> 문자열 -> 정렬 -> 정수(문자열 파싱 + 내장 정렬 방식)
// 문자열 객체 생성 및 파싱 오버헤드가 발생하나 LL의 데이터 최대 길이가 19자리에 불과해 성능 저하가 0에 수렴

long long solution(long long n) {

    string numList = to_string(n);
    sort(numList.begin(), numList.end(), greater<char>());
    return stoll(numList);
}