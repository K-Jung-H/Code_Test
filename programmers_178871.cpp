#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    unordered_map<string, int> grades;
    
    for(int i = 0; i < players.size(); i++)
        grades[players[i]] = i;

    
    for(const string& call: callings)
    {
        int current_grade = grades[call];
        int new_grade = current_grade - 1;

        grades[players[new_grade]] = current_grade;
        grades[players[current_grade]] = new_grade;
        
        swap(players[new_grade], players[current_grade]);
    }
    
    return players;
}