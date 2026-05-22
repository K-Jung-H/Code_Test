#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> mats, vector<vector<string>> park) {
    int H = park.size();
    int W = park[0].size();
    
    sort(mats.rbegin(), mats.rend());
    
    for(int mat_size : mats)
        for(int y = 0; y + mat_size <= H; y++) 
            for(int x = 0; x + mat_size <= W; x++) {
                
                bool is_success = true;
                
                for(int dy = 0; dy < mat_size; dy++) {
                    for(int dx = 0; dx < mat_size; dx++) {
                        if(park[y + dy][x + dx] != "-1") {
                            is_success = false;
                            break; 
                        }
                    }
                    
                    if(is_success == false) 
                        break; 
                    
                }
                
                if(is_success) 
                    return mat_size;
                
                
            }
        
    
    
    return -1;
}