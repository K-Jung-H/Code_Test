#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
   bool is_success = false;

    reverse(cards1.begin(), cards1.end());
    reverse(cards2.begin(), cards2.end());
    reverse(goal.begin(), goal.end());

    while(!is_success)
    {
        string s = goal.back();
        goal.pop_back();
        
        if(!cards1.empty() && s == cards1.back())
            cards1.pop_back();
        else if(!cards2.empty() && s == cards2.back())
            cards2.pop_back();
        else
            break;

        if(goal.empty())
            is_success = true;
    }


    return is_success ? "Yes" : "No";
}

// Queue 활용 해결법
#include <queue> 

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    queue<string> q1; for(const string& s : cards1) q1.push(s);
    queue<string> q2; for(const string& s : cards2) q2.push(s);
    queue<string> q_goal; for(const string& s : goal) q_goal.push(s);

    while (!q_goal.empty()) {
        string target = q_goal.front(); 

        if (!q1.empty() && q1.front() == target) {
            q1.pop();
            q_goal.pop();
        }
        else if (!q2.empty() && q2.front() == target) {
            q2.pop();
            q_goal.pop();
        }
        else {
            return "No";
        }
    }

    return "Yes";
}