#include <numeric>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n, long long k) {
    vector<int> answer(n);
    
    iota(answer.begin(),answer.end(),1);
    
    for(int i = 1; i <  k; i++)
        next_permutation(answer.begin(), answer.end());

    
    return answer;
}

//=============================================================

#include <vector>

using namespace std;

vector<int> solution(int n, long long k) {
    vector<int> answer;
    vector<int> people;
    vector<long long> fact(n + 1, 1);
    for (int i = 1; i <= n; i++) {
        people.push_back(i);
    }

    for (int i = 1; i <= n; i++) {
        fact[i] = fact[i - 1] * i;
    }

    k--; 

    for (int i = n; i > 0; i--) {
        long long chunk = fact[i - 1]; 
        
        int idx = k / chunk; 
        
        answer.push_back(people[idx]);
        people.erase(people.begin() + idx);
        
        k %= chunk; 
    }

    return answer;
}