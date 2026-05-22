#include <string>
#include <vector>

using namespace std;

string toBinary(int num)
{
    string b = "";
    
    for(int n = num; n > 0;  n/=2)
        b += to_string(n % 2);
    
    return b;
}

int solution(int n) {
    int answer = 0;
    int new_num = n + 1;
    int count_1_a = 0;
    int count_1_b = 0;
    
    string s1 = toBinary(n);
        
    for(char c : s1)
        if(c == '1')    
            count_1_a += 1;
    
    while(answer == 0)
    {      
        string new_s = toBinary(new_num);

        for(char c : new_s)
            if(c == '1')    
                count_1_b += 1;
        
        if(count_1_a == count_1_b)
            answer = new_num;
            

        new_num += 1;
    }
    
    return answer;
}