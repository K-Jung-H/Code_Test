#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> students(n + 2, 1);
    
    for (int l : lost) 
        students[l]--;
    
    for (int r : reserve) 
        students[r]++;
    
    
    for (int i = 1; i <= n; i++) 
        if (students[i] == 0) {
            if (students[i - 1] == 2) {
                students[i]++;
                students[i - 1]--;
            } 
            else if (students[i + 1] == 2) {
                students[i]++;
                students[i + 1]--;
            }
        }
    
    
    for (int i = 1; i <= n; i++) 
        if (students[i] >= 1) 
            answer++;
        
    
    
    return answer;
}