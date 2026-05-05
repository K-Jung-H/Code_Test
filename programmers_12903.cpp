#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    int length = s.size();
    bool is_even = length % 2 == 0;
    int start_index = 0;
    
    start_index = is_even ? length/2 -1 : length/2;
    return is_even ? s.substr(start_index, 2) : s.substr(start_index, 1);

}

// 압축 버전
// (s.size() - 1) / 2 : 홀수/짝수 상관없이 항상 정확한 시작 인덱스 연산
// 2 - (s.size() % 2) : 짝수면 2글자, 홀수면 1글자를 추출
 
string solution(string s) {
    return s.substr((s.size() - 1) / 2, 2 - (s.size() % 2));
}