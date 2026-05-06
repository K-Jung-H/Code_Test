#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    for (int i = 0; i < arr1.size(); ++i)
    {
        transform(arr1[i].begin(), arr1[i].end(), arr2[i].begin(), arr1[i].begin(), [](int a, int b){return a+b;});
    }

    return arr1;
}