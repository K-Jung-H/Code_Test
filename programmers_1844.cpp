#include<vector>
#include<queue>
using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

struct Point
{
    int x;
    int y;
    int d;
};

int solution(vector<vector<int> > maps)
{
    int answer = -1;
    
    int H = maps.size();
    int W = maps[0].size();
    
    vector<vector<bool>> map_status(H, vector<bool>(W, true));
    Point current_pos = {0,0};
    queue<Point> q;
    
    q.push({0, 0, 1});
    map_status[0][0] = false;
    
    while(!q.empty())
    {        
        Point curr_pos = q.front();
        q.pop();
        
        
        if(curr_pos.x == W - 1 && curr_pos.y == H - 1)
            return curr_pos.d;
        
        
        for(int i = 0; i < 4; i++)
        {
            int new_x = curr_pos.x + dx[i];
            int new_y = curr_pos.y + dy[i];
            
            if(new_x < 0 || new_x > W - 1)
                continue;
            if(new_y < 0 || new_y > H - 1)
                continue;
            
            if(maps[new_y][new_x] != 0 && map_status[new_y][new_x] != false)
            {
                map_status[new_y][new_x] = false;
                q.push({new_x, new_y, curr_pos.d + 1});
            }
        }
        
    }
    
    return answer;
}