#include <vector>

using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    vector<int> stack;
    
    for(int n : ingredient) {
        stack.push_back(n);
        
        if (stack.size() >= 4) {
            int size = stack.size();
            
            if (stack[size - 4] == 1 && 
                stack[size - 3] == 2 && 
                stack[size - 2] == 3 && 
                stack[size - 1] == 1) {
                
                stack.pop_back();
                stack.pop_back();
                stack.pop_back();
                stack.pop_back();
                
                answer += 1;
            }
        }
    }
    
    return answer;
}