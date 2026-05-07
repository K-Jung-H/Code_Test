#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;

    for (int a = 0; a < numbers.size(); ++a)
        for (int b = a+1; b < numbers.size(); ++b)
            answer.push_back(numbers[a]+numbers[b]);

    sort(answer.begin(),answer.end());
    answer.erase(unique(answer.begin(), answer.end()), answer.end());

    
    return answer;
}

// Set 활용
#include <set>

vector<int> solution(vector<int> numbers) {
    set<int> st;
    vector<int> answer;

    for (int a = 0; a < numbers.size(); ++a)
        for (int b = a+1; b < numbers.size(); ++b)
            st.insert(numbers[a]+numbers[b]);
    answer.assign(st.begin(), st.end());    
    return answer;
}