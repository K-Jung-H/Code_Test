#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    for (vector<int> command : commands)
    {
        vector<int> temp_list;
        int i = command[0];
        int j = command[1];
        int k = command[2];
                
        temp_list.assign(array.begin() + i - 1, array.begin() + j);
        sort(temp_list.begin(), temp_list.end());
        answer.push_back(temp_list[k - 1]);
    }
    

    return answer;
}