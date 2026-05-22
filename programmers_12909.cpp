#include<string>
#include<stack>
#include <iostream>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<char> a;
    
    for(const char& c : s)
    {
        if(c == ')')
        {
            if(a.empty())
                return false;
            else
                a.pop();
        }
        else
            a.push(c);    
    }
    
    return a.empty() ? answer : false;
    
}
    
    