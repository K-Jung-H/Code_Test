#include <string>
#include <vector>
#include <stack>

using namespace std;

struct SumState
{
    int sum;
    int index;
};

int solution(vector<int> numbers, int target) {
    int answer = 0;
    stack<SumState>s;
    s.push({0,0});
    
    while(!s.empty())
    {
        SumState curr = s.top();
        s.pop();
                    
        if (curr.index == numbers.size()) {
            if (curr.sum == target) 
                answer++;
        }
        else {
            s.push({curr.sum + numbers[curr.index], curr.index + 1});
            s.push({curr.sum - numbers[curr.index], curr.index + 1});
        }
    }
    
        
    
    return answer;
}