#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<string>> board, int h, int w) {
    int answer = 0;
    int board_area = board.size();
    int dx[4] = { -1, 1, 0, 0};
    int dy[4] = { 0, 0, -1, 1};
    
    string color = board[h][w];
    
    for(int i = 0; i < 4; i++)
    {
        int y = clamp(h + dy[i], 0, board_area-1);
        int x = clamp(w + dx[i], 0, board_area-1);
        
        if(h == y && w == x)   
            continue;
        if(board[y][x] == color)
           answer += 1;        
    }
        
    
    return answer;
}