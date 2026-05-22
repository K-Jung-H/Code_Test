#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

int solution(string message, vector<vector<int>> spoiler_ranges) 
{
    int answer = 0;
    unordered_map<string, bool> only_spoiler;
    int last_space_pos = 0;
    int n = message.size();

    for (int i = 0; i <= n; i++) 
        if (i == n || message[i] == ' ') 
        {
            if (last_space_pos < i) 
            {
                string word = message.substr(last_space_pos, i - last_space_pos);
                int word_start = last_space_pos;
                int word_end = i - 1;
                
                bool is_spoiler = false;
                for (const auto& range : spoiler_ranges) 
                {
                    if (word_start <= range[1] && word_end >= range[0]) 
                    {
                        is_spoiler = true;
                        break;
                    }
                }

                if (is_spoiler) 
                {
                    if (only_spoiler.find(word) == only_spoiler.end()) 
                        only_spoiler[word] = true;
                    
                } 
                else 
                    only_spoiler[word] = false;
                
            }
            last_space_pos = i + 1;
        }
    

    for (const auto& info : only_spoiler) 
        if (info.second == true) 
            answer += 1;
        

    return answer;
}