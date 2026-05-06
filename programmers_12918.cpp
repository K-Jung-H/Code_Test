#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(string s) {
    bool answer = true;

    int length = s.size();

    if(length != 4 && length != 6)
        return false;

    return all_of(s.begin(),s.end(), ::isdigit);
    // for(const char& c : s)
    // {
    //     if( c < '0' || c > '9')
    //         return false;
    // }
        
    return answer;
}