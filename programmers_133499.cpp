#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<string> babbling) {
    vector<string> test_list(4);
    test_list[0] = "aya";
    test_list[1] = "ye";
    test_list[2] = "woo";
    test_list[3] = "ma";
    
    int answer = 0;

    for(string& str : babbling)
    {
        bool is_success = true;

        for(int i = 0; i < 4; i++)
        {
            while(true)
            {
                auto it = str.find(test_list[i]);

                if(it != string::npos)
                    str.replace(it, it + test_list[i].size(), to_string(i));
                else
                    break;                    
            }
        }

        for(int i = 0; i < 4; i++)
        {
            auto it = str.find(to_string(i) + to_string(i));
            if(it != string::npos)
            {
                is_success = false;
                break;
            }                
            
        }   
        
        is_success &= all_of(str.begin(), str.end(), [](char c){ return isdigit(c); });
                           
        if(is_success)
            answer += 1;
        
    }
    
    return answer;

}


int solution(vector<string> babbling) {
    int answer = 0;

    for(int i;i<babbling.size();i++)
    {
        string temp1="";
        string temp2="";
        for(char c:babbling[i])
        {
            temp1+=c;
            if(temp1 == "aya"||temp1 == "ye"||temp1 == "woo"||temp1 == "ma")
            {
                if(temp2 == temp1) break;
                temp2=temp1;
                temp1="";
            }
        }
        if(temp1.size()==0) answer++;
    }
    return answer;
}