#include <string>
#include <vector>

using namespace std;

// i의 약수를 구하는 함수
int getFactor(int n) {
    int factor_num = 0;

    for (int i = 1; i * i <= n; i++)
    {
        if(n % i == 0)
        {
            factor_num += 1;

            if(n / i != i)
                factor_num += 1;
        }            
    }
    return factor_num;
}

// i의 약수를 구하는 함수를 활용
// 편의성, 확장성
int solution(int number, int limit, int power) {
    int iron = 0;
    for (int i = 1; i <= number; i++)
    {
        int i_factor = getFactor(i);
        if(i_factor > limit)
            i_factor = power;
        
        iron += i_factor;
    }
    
    return iron;
}

// 에라토스테네스의 체 원리 활용
// 속도 우선
int solution(int number, int limit, int power) {
    vector<int> counts(number + 1, 0);

    for (int i = 1; i <= number; i++) 
        for (int j = i; j <= number; j += i) 
            counts[j]++;
    
    int total_iron = 0;

    for (int i = 1; i <= number; i++) {
        if (counts[i] > limit) 
            total_iron += power;
        else 
            total_iron += counts[i];
    }

    return total_iron;
}