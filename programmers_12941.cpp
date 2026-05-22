#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;
    sort(A.begin(),A.end(), less<int>());
    sort(B.begin(),B.end(), greater<int>());
    
    transform(A.begin(), A.end(), B.begin(), B.begin(), [](int a, int b) {return a*b;});
    
    answer = accumulate(B.begin(),B.end(), 0);
    
    return answer;
}