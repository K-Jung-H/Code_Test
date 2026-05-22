#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    unordered_map<string, int> idx_map;
    
    idx_map["code"] = 0;
    idx_map["date"] = 1;
    idx_map["maximum"] = 2;
    idx_map["remain"] = 3;
    
    
    data.erase(remove_if(data.begin(), data.end(), [idx = idx_map[ext], val_ext](vector<int>& info){ return !(info[idx] < val_ext);}), data.end());

    sort(data.begin(), data.end(), [idx = idx_map[sort_by]](const vector<int>& data_1, const vector<int>& data_2) {return data_1[idx] < data_2[idx]; });
    return data;
}