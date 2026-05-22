#include <vector>
#include <algorithm>

using namespace std;

const int INF = 200000000; 

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    vector<vector<int>> dist(n + 1, vector<int>(n + 1, INF));
    
    for (int i = 1; i <= n; i++) {
        dist[i][i] = 0;
    }
    
    for (const auto& f : fares) {
        dist[f[0]][f[1]] = f[2];
        dist[f[1]][f[0]] = f[2];
    }
    
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    
    int answer = INF;
    for (int k = 1; k <= n; k++) {
        answer = min(answer, dist[s][k] + dist[k][a] + dist[k][b]);
    }
    
    return answer;
}