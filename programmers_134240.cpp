#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(vector<int> food) {
    string answer = "";
    string reverse_answer = "";

    for(int i = 1; i < food.size(); ++i)
    {
        int N = food[i] / 2;
        string s(N, '0' + i);
        answer += s;
    }

    reverse_answer = answer;
    reverse(reverse_answer.begin(), reverse_answer.end());
    answer = answer + "0" + reverse_answer;
    return answer;
}


// Insert 해결법
// 더 간결하지만 연산량이 더 많음
string solution(vector<int> food) {
    string answer = "0";

    for(int i = food.size() - 1; i >= 1; --i) {
        string s(food[i] / 2, '0' + i);
        
        answer.insert(0, s);
        answer.append(s);
    }

    return answer;
}