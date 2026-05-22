#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    int lux = 50, luy = 50, rdx = 0, rdy = 0;
    
    for(int i = 0; i < wallpaper.size(); i++)
    {
        for(int k = 0; k < wallpaper[i].size(); k++)
        {
            if(wallpaper[i][k] == '#')
            {
                lux = min(lux, i);
                luy = min(luy, k);
                
                rdx = max(rdx, i + 1);
                rdy = max(rdy, k + 1);
            }
        }
    }
    
    answer.push_back(lux);
    answer.push_back(luy);
    answer.push_back(rdx);
    answer.push_back(rdy);
    
    return answer;
}