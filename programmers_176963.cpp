#include <string>
#include <vector>
#include <map>

using namespace std;

// unordered_map 방식이 더 성능이 좋음
vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    map<string, int> conditions;
    vector<int> answer;

    for (int i = 0; i < name.size(); ++i)
        conditions[name[i]] = yearning[i];
    
    for (const vector<string>& photo_data : photo)
    {
        int case_answer = 0;
        for (const string& person : photo_data)
        {
            auto info = conditions.find(person);
            if(info != conditions.end())
                case_answer += info->second;
        }
        answer.push_back(case_answer);
    }

    return answer;
}