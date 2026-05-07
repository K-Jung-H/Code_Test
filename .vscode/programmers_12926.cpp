#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";

    for (char c : s)
    {
        if('A' <= c && c <= 'Z')
            answer += (c - 'A' + n) % 26 + 'A';
        else if('a' <= c && c <= 'z')
            answer += (c - 'a' + n) % 26 + 'a';
        else 
            answer += c;
    }

    return answer;
}
