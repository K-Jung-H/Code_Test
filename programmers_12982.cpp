#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// STL 활용
// 비효율적 구조
int solution(vector<int> d, int budget) {
    
    auto calc = [&budget](int n){ budget -= n; return budget >= 0; };

    sort(d.begin(), d.end(), less<int>());

    int answer = count_if(d.begin(), d.end(), calc);
    return answer;
}

// 단순하지만 효율적
int solution(vector<int> d, int budget) {
    sort(d.begin(), d.end());
    
    int answer = 0;
    
    for (int cost : d) {
        if (budget < cost)
            break;
        
        budget -= cost;
        answer++;
    }
    
    return answer;
}