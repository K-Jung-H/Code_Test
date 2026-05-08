#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool check(string s1, string s2, int n)
{
    if(s1[n] != s2[n])
        return s1[n] < s2[n];
    else
        return s1 < s2;
}

vector<string> solution(vector<string> strings, int n) {

    auto lambda = [n](string s1, string s2){ return check(s1, s2, n);};
    sort(strings.begin(), strings.end(), lambda);


    return strings;
}


// 최적화 

vector<string> solution(vector<string> strings, int n) {

    auto lambda = [n](const string& s1, const string& s2){ return (s1[n] != s2[n]) ? (s1[n] < s2[n]) : (s1 < s2); };
    sort(strings.begin(), strings.end(), lambda);


    return strings;
}
