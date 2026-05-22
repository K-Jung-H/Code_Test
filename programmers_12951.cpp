#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    char last_c = ' ';
    for(char& c: s)
    {
        if(last_c == ' ')
            c = toupper(c);
        else
            c = tolower(c);
        last_c = c;
    }
    return s;
}