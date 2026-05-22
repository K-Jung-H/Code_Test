#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    int area = board.size();
    vector<int> stack;
    for(int n : moves)
    {
        n -= 1;
        for(int i = 0; i < area; i++)
        {
            int doll = board[i][n];
            
            
            if(doll)
            {
                if(!stack.empty() && stack.back() == doll)
                {
                    stack.pop_back();
                    answer += 2;
                }
                else
                    stack.push_back(doll);
                
                board[i][n] = 0;
                break;
            }
        }        
        
    }
    return answer;
}