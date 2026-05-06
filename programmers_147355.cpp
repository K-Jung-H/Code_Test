#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    int len_t = t.size();
    int len_p = p.size();
    string s = "";

    for (int i = 0; i <= len_t - len_p; ++i)
    {
        s = t.substr(i, len_p);

        long long a = stoll(s);
        long long b = stoll(p);
        
        if(a <= b)
            answer += 1;

    }

    
    return answer;
}
