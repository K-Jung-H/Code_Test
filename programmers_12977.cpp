#include <vector>
#include <iostream>
using namespace std;


int solution(vector<int> nums) {
    int answer = 0;

    vector<bool>is_prime(3000 + 1,true);
    is_prime[0] = false;
    is_prime[1] = false;

    for(int i = 2; i * i <= 3000; i++)
    {
        if(is_prime[i])
            for(int k = i * i; k <= 3000; k+= i)
                is_prime[k] = false;           
    }
    
    
    for(int a = 0; a < nums.size(); a++)
        for(int b = a + 1; b < nums.size(); b++)
            for(int c = b + 1; c < nums.size(); c++)
            {
                if(is_prime[nums[a]+nums[b]+nums[c]])
                    answer += 1;
            }



    return answer;
}