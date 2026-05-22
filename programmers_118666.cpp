#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    unordered_map<char, int> score;

   
    for(int i = 0; i < choices.size(); i++)
    {
        int t = choices[i] - 4;
        if(t < 0)
            score[survey[i][0]] -= t;
        else
            score[survey[i][1]] += t;
    }
    
    score['R'] >= score['T'] ? answer += 'R' : answer += 'T';
    score['C'] >= score['F'] ? answer += 'C' : answer += 'F';
    score['J'] >= score['M'] ? answer += 'J' : answer += 'M';
    score['A'] >= score['N'] ? answer += 'A' : answer += 'N';    

    return answer;
}