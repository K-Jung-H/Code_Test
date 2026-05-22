#include <string>
#include <vector>

using namespace std;

// m + 1 + m + 2 + m + 3 + m + 4 + m + 5 = 15 -> 5m = 0 -> m = 0
// m + 1 + m + 2 + m + 3  = 15 -> 3m = 9 -> m = 3
// m + 1 + m + 2 = 15 -> 2m = 12 -> m = 6
// m = 15

// 5m + 0 + 1 + 2 + 3 + 4
// 3m + 0 + 1 + 2
// 2m + 0 + 1
// 1m + 0
// = 15
    
int F(int c)
{
    if(c == 0)
        return 0;
    
    return c + F(c-1);
}
    
    
int solution(int n) {
    int answer = 0;
    
    for(int m = 1; m <= n; m++)
    {
        int temp = n - F(m-1);
        if(temp >= m && temp % m == 0)
            answer += 1;
    }
    
    return answer;
}

