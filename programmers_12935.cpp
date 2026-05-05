#include <string>
#include <vector>
#include <algorithm>

using namespace std;


// min_element 활용
vector<int> solution(vector<int> arr) {
    auto min_x = min_element(arr.begin(), arr.end());
    arr.erase(min_x);
    
    if(arr.empty())
        arr.push_back(-1);
    return arr;
}