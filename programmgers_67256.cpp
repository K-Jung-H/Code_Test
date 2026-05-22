#include <string>
#include <vector>
#include <cmath>

using namespace std;

int get_distance(int start, int target) {
    int start_row = (start - 1) / 3;
    int start_col = (start - 1) % 3;
    
    int target_row = (target - 1) / 3;
    int target_col = (target - 1) % 3;
    
    return abs(start_row - target_row) + abs(start_col - target_col);
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    
    int Last_L = 10;
    int Last_R = 12;
    
    for(int num : numbers) {
        if(num == 0) {
            num = 11;
        }
        
        if(num % 3 == 1) {
            answer += "L";
            Last_L = num;
        }
        else if(num % 3 == 0) {
            answer += "R";
            Last_R = num;
        }
        else {
            int dis_L = get_distance(Last_L, num);
            int dis_R = get_distance(Last_R, num);
            
            if(dis_L == dis_R) {
                if(hand == "left") {
                    answer += "L";
                    Last_L = num;
                } else {
                    answer += "R";
                    Last_R = num;
                }
            }
            else if(dis_L < dis_R) {
                answer += "L";
                Last_L = num;
            }
            else {
                answer += "R";
                Last_R = num;
            }
        }
    }
    
    return answer;
}