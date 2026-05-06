#include <string>
#include <vector>

using namespace std;

int solution(vector<int> number) {
    int answer = 0;

    for(int a = 0; a < number.size(); ++a) 
        for(int b = a + 1; b < number.size(); ++b) 
            for(int c = b + 1; c < number.size(); ++c) 
                answer += number[a]+number[b]+number[c] == 0 ? 1 : 0;

    return answer;
}