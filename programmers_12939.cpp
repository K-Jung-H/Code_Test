#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    vector<int> stack;

    string num = "";
    
    for(const char& c : s)
    {
        if(c != ' ')
            num += c;
        else
        {
            int n = stoi(num);
            stack.push_back(n);
            num = "";
        }   
    }
    
    int n = stoi(num);
    stack.push_back(n);
    
    int M = *max_element(stack.begin(),stack.end());
    int m = *min_element(stack.begin(),stack.end());
    
    return to_string(m) + " " + to_string(M);
}