#include <bits/stdc++.h>
using namespace std;

#define PI acos(-1)
#define EPS 1e-9
#define MOD 1e9+7
#define SET(a , x) memset(a , x , sizeof(a))
#define Fast ios_base::sync_with_stdio(false)

int N , E , u , v , w;
unsigned int graph[401][401] , p[401][401];

void Path(int i , int j) {
    if(i != j) Path(i , p[i][j]);
    cout << j << " ";
}

int main(){
    Fast;
    
    for (int i = 1; i <= 400; i++) {
        for (int j = 1; j <= 400; j++) {
            graph[i][j] = INT_MAX;
        }
    }
    
    cin >> N >> E;
    
    for (int i = 1; i <= E; i++) {
        cin >> u >> v >> w;
        graph[u][v] = w;
    }
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            p[i][j] = i;
        }
    }
    
    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (graph[i][k]+graph[k][j] < graph[i][j]) {
                    graph[i][j] = graph[i][k]+graph[k][j];
                    p[i][j] = p[k][j];
                }
            }
        }
    }
    
    int Q;
    cin >> Q;
    for (int i = 1; i <= Q; i++) {
        cin >> u >> v;
        cout << graph[u][v] << endl;
        Path(u , v);
    }
    
    return 0;
}
