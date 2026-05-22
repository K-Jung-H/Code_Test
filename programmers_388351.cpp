#include <string>
#include <vector>

using namespace std;

bool checkCondition(int scheduleTime, int arriveTime)
{
    int schedule = (scheduleTime / 100) * 60 + scheduleTime % 100;
    int arrive = (arriveTime / 100) * 60 + arriveTime % 100;
    
    schedule += 10;
         
    return schedule >= arrive;
    
}

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    
    for(int i = 0; i < timelogs.size(); i++)
    {
        bool is_success = true;
        for(int d = 0; d < 7; d++)
        {            
            int today = (startday + d) % 7; 
            if (today == 6 || today == 0) 
                continue;
            
            is_success &= checkCondition(schedules[i], timelogs[i][d]);
        }
        
        answer = is_success ? answer+1 : answer;
    }
    return answer;
}