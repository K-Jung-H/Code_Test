#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    int s_x = 0, s_y = 0;
    int H = park.size();
    int W = park[0].size();
    
    for(int y = 0; y < H; y++) {
        for(int x = 0; x < W; x++) {
            if(park[y][x] == 'S') {
                s_x = x;
                s_y = y;
            }
        }
    }
        
    for(string s : routes) {
        int num = s[2] - '0';
        int dx = 0, dy = 0;
        
        if(s[0] == 'E') { dx = 1; dy = 0; }
        else if(s[0] == 'W') { dx = -1; dy = 0; }
        else if(s[0] == 'N') { dx = 0; dy = -1; }
        else if(s[0] == 'S') { dx = 0; dy = 1; }
        
        int temp_x = s_x;
        int temp_y = s_y;
        bool can_move = true;
        
        for(int i = 0; i < num; i++) {
            temp_x += dx;
            temp_y += dy;
            
            if(temp_y < 0 || temp_y >= H || temp_x < 0 || temp_x >= W) {
                can_move = false;
                break; 
            }
            
            if(park[temp_y][temp_x] == 'X') {
                can_move = false;
                break; 
            }
        }
        
        if (can_move) {
            s_x = temp_x;
            s_y = temp_y;
        }
    }
    
    vector<int> answer;
    answer.push_back(s_y);
    answer.push_back(s_x);
    
    return answer;
}