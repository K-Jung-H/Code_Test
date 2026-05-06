using namespace std;

long long getMoney(long long price, long long count)
{
    if(count == 1)
        return price;
    else
        return (price * count) +  getMoney(price, count -1);
}

// 재귀방식 사용
long long solution(int price, int money, int count)
{
    long long answer = getMoney(price, count) - money;
    return answer > 0 ? answer : 0;
}

// 등차수열의 합 공식 이용
// S = N(N+1)/2
long long soultion(int price, int money, int count)
{
    long long total_cost = 1LL * price * count * (count + 1) / 2;
    return total_cost > money ? total_cost - money : 0;
}