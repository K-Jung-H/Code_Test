#include <string>
#include <vector>
#include <map>
#include <array>

using namespace std;

void initialize(map<string, int>& M)
{
    array<string, 10> temp = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
    
    for (int i = 0; i < temp.size(); ++i)
        M[temp[i]] = i;
}

// 초기 답안
int solution(string s) {
    string answer = "";
    map<string, int> M;

    initialize(M);

    int A = 0, B = 1;
    while(A < s.size())
    {
        
        if('0' <= s[A] && s[A] <= '9')
        {
            answer += s[A];
            A += 1;
            B = 1;       
            continue;
        }

        string text = s.substr(A, B);

        if(M.find(text) == M.end())
        {
            ++B;
        }
        else
        {
            answer += to_string(M[text]);
            A += B;
            B = 0;
        }

    }

    return stoi(answer);
}


// String 내장 함수 활용
int solution(string s) {
    map<string, int> M;

    initialize(M);

    for (pair<string, int> num : M)
    {
        while(true)
        {
            size_t result = s.find(num.first);
            if(result == string::npos)
                break;
            else
                s.replace(result, num.first.length(), to_string(num.second));
        }    
    }

    return stoi(s);
}
