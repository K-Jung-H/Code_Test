#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string X, string Y) {
    string answer = "";
    vector<int> countX(10, 0);
    vector<int> countY(10, 0);
    
    for(const char& c : X)
        countX[c - '0'] += 1;
   
    
    for(const char& c : Y)
        countY[c - '0'] += 1;

    for(int i = 9; i >= 0; i--)
    {
        int count = min<int>(countY[i], countX[i]);
        
        for(int k = 0; k < count; k++)
            answer += to_string(i);

    }
    
    if(answer == "") return "-1";
    if(answer[0] == '0') return "0";
    return answer;
}