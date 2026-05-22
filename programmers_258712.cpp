#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    int n = friends.size();
    unordered_map<string, int> f_id;
    for (int i = 0; i < n; ++i) {
        f_id[friends[i]] = i;
    }

    vector<vector<int>> gift_table(n, vector<int>(n, 0));
    vector<int> gift_index(n, 0);

    for (const string& data : gifts) {
        size_t space_pos = data.find(" ");
        string A = data.substr(0, space_pos);
        string B = data.substr(space_pos + 1);

        int id_A = f_id[A];
        int id_B = f_id[B];

        gift_table[id_A][id_B] += 1;
        gift_index[id_A] += 1;
        gift_index[id_B] -= 1;
    }

    vector<int> next_month(n, 0);

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (gift_table[i][j] > gift_table[j][i]) {
                next_month[i] += 1;
            } else if (gift_table[i][j] < gift_table[j][i]) {
                next_month[j] += 1;
            } else {
                if (gift_index[i] > gift_index[j]) {
                    next_month[i] += 1;
                } else if (gift_index[i] < gift_index[j]) {
                    next_month[j] += 1;
                }
            }
        }
    }

    return *max_element(next_month.begin(), next_month.end());
}