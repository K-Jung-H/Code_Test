#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> seoul) {
    
    auto it = find(seoul.begin(), seoul.end(),"Kim");
    int x = distance(seoul.begin(), it);

    return "김서방은 "+ to_string(x) + "에 있다";
}