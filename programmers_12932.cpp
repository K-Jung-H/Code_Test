#include <string>
#include <vector>

using namespace std;

// 자연수 n의 각 자릿수를 뒤집어 벡터로 반환하는 함수 (성능 우선 버전)
// 입력된 자연수의 각 자릿수를 역순으로 추출하여 벡터에 저장합니다.
// 산술 연산을 사용하여 효율적으로 처리합니다.
vector<int> solution(long long n) {
    vector<int> answer;

    answer.push_back(n % 10);
    
    while(n /= 10)
    {
        answer.push_back(n % 10);
    }

    return answer;
}

// 자연수 n의 각 자릿수를 뒤집어 벡터로 반환하는 함수 (문자열 버전)
// 입력된 자연수를 문자열로 변환한 후, 역순으로 각 문자를 숫자로 변환하여 벡터에 저장합니다.
// 문자열 변환을 사용하여 간단하게 처리합니다.
vector<int> solution(long long n) {
    vector<int> answer;
    
    string numList = to_string(n);

    for(auto it =  numList.rbegin(); it != numList.rend(); ++it)
        answer.push_back(*it - '0');

    return answer;
}