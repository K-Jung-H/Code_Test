#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    bool isUpper = true;

    for(char& t : s)
    {
        if(isalpha(t))
        {   
            t = isUpper ? toupper(t) : tolower(t);
            isUpper = !isUpper;
        }
        else
            isUpper = true;

    }
}