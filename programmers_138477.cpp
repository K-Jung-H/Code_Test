#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// vector 만으로 해결하기
vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    vector<int> Hall_of_Fame;
    
    reverse(score.begin(), score.end());

    while(!score.empty())
    {
        Hall_of_Fame.push_back(score.back());
        score.pop_back();

        sort(Hall_of_Fame.begin(), Hall_of_Fame.end(), greater<int>());


        while(Hall_of_Fame.size() > k)
            Hall_of_Fame.pop_back();
        
        answer.push_back(Hall_of_Fame.back());
    }

    return answer;
}

// 우선순위 Queue 구조 활용하기
#include <queue> 

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    
    priority_queue<int, vector<int>, greater<int>> pq; 

    for (int s : score) {
        pq.push(s); 

        if (pq.size() > k) 
            pq.pop(); 
        
        answer.push_back(pq.top()); 
    }

    return answer;
}