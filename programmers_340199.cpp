#include <string>
#include <vector>

using namespace std;

int solution(vector<int> wallet, vector<int> bill) {
    int answer = 0;
    int wallet_long = max<int>(wallet[0], wallet[1]);
    int wallet_short = min<int>(wallet[0], wallet[1]);

    int bill_long = max<int>(bill[0], bill[1]);
    int bill_short = min<int>(bill[0], bill[1]);
    

    while(wallet_long < bill_long || wallet_short < bill_short)
    {
        bill_long /= 2;
        
        if(bill_long < bill_short)
            swap(bill_long, bill_short);
        
        answer++;
    }

    return answer;
}