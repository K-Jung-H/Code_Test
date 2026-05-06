#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;

    for(int n : arr) {
        if(answer.empty())
            answer.push_back(n);
        else if(answer.back() != n)
            answer.push_back(n);
    }

    return answer;
}

// unique 활용
vector<int> solution(vector<int> arr) {
    arr.erase(unique(arr.begin(), arr.end()),arr.end());
    return arr;
}
