#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    unordered_map<char, int> min_list;
    
    for(string s : keymap)
    {
        int button_count = 0;
        for(const char c : s)
        {
            button_count += 1;
            if(min_list.find(c) == min_list.end())
                min_list[c] = button_count;
            else if(min_list[c] > button_count)
                min_list[c] = button_count;
            
        }
    }
    
    
    for(string s : targets)
    {
        int button_count = 0;
        for(const char c : s)
        {
            if(min_list.find(c) == min_list.end())
            {
                button_count = -1;
                break;
            }
            else
                button_count += min_list[c];
        }        
        answer.push_back(button_count);
    }
    
    return answer;
}