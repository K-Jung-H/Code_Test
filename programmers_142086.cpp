#include <string>
#include <vector>
#include <map>

using namespace std;

// Map 해결법
vector<int> solution(string s) {
    vector<int> answer;
    map<char, int> table;

    for (int i = 0; i < s.size(); ++i)
    {
        char c = s[i];

        if(table.find(c) == table.end())
            answer.push_back(-1);
        else
            answer.push_back(i - table[c]);

        table[c] = i;
    }
        
    return answer;
}

//Vector 해결법
vector<int> solution(string s) {
    vector<int> answer;
    vector<int> record(26, -1);


    for (int i = 0; i < s.size(); ++i)
    {
        int index = s[i] - 'a';
        int status = record[index];
        
        if(status == -1)
            answer.push_back(-1);
        else
            answer.push_back(i - status);

        record[index] = i;
    }
        
    return answer;
}