#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

int solution(vector<int> nums)
{
    unordered_set<int> pokemon_types(nums.begin(), nums.end());

    int max_pick = nums.size() / 2;

    return min((int)pokemon_types.size(), max_pick);
}