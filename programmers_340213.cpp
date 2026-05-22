#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int MM_to_SS(const string& time_str)
{
    int min = stoi(time_str.substr(0, 2));
    int sec = stoi(time_str.substr(3, 2));
    return min * 60 + sec;
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    int video_length = MM_to_SS(video_len);
    int position = MM_to_SS(pos);
    int opening_start = MM_to_SS(op_start);
    int opening_end = MM_to_SS(op_end);
    
    auto SkipOpening = [&]() {
        if (opening_start <= position && position <= opening_end) {
            position = opening_end;
        }
    };
    
    SkipOpening();
    
    for (const string& command : commands) {
        if (command == "next") {
            position += 10;
        } else if (command == "prev") {
            position -= 10;
        }
        
        position = clamp(position, 0, video_length);
        
        SkipOpening();
    }
    
    int pos_minute = position / 60;
    int pos_sec = position % 60;
    
    string answer = "";
    
    if (pos_minute < 10) answer += "0";
    answer += to_string(pos_minute) + ":";
    
    if (pos_sec < 10) answer += "0";
    answer += to_string(pos_sec);
    
    return answer;
}