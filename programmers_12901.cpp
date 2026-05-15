#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    int month[13] = { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    string week[] = { "FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU" };
    int date_sum = 0;

    for(int i = 1; i <= a; i++)
        date_sum += month[i-1];
    
    date_sum += b;
    
    return week[(date_sum -1 + 7) % 7];
}
