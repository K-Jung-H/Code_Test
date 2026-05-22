#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int match_count = 0;
    int zero_count = 0;
    int rank[7] = {6,   6,   5,   4,   3,   2,   1};
    
    for (int n : lottos) {
        if (n == 0) {
            zero_count += 1;
        } else {
            auto it = find(win_nums.begin(), win_nums.end(), n);
            if (it != win_nums.end()) {
                match_count += 1;
            }
        }
    }
    
    answer.push_back(rank[match_count + zero_count]);
    answer.push_back(rank[match_count]);
    
    return answer;
}