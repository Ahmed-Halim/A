#include <bits/stdc++.h>
using namespace std;

#define PI acos(-1)
#define EPS 1e-9
#define MOD 1e9+7
#define SET(a) memset(a , 0 , sizeof(a))
#define Fast ios_base::sync_with_stdio(false)

int N , E , u , v;
vector <vector <int>> adj;
vector <int> DFS , visited;
int Cycle = 0 , Bidirctional = 0 , Forward = 0;

void GraphCheck (int u) {
    visited[u] = 2;
    for (auto v : adj[u]) {
        if (visited[v] == 0) {
            DFS[v] = u;
            GraphCheck(v);
        }
        else if (visited[v] == 2) {
            if (v == DFS[u]) {
                Bidirctional++;
                cout << "Bidirctional : " << u << " " << v << " - " << v << " " << u << endl;
            } else {
                Cycle++;
                cout << "Cycle : " << u << " " << v << endl;
            }
        }
        else if (visited[v] == 1) {
            Forward++;
            cout << "Forword : " << u << " " << v << endl;
        }
    }
    visited[u] = 1;     
}

int main(){
    Fast;
    
    cin >> N >> E;
    adj = vector <vector <int>> (N+1);
    visited = vector <int> (N+1);
    DFS = vector <int> (N+1);
    
    for (int i = 0; i < E; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
    }
    
    for (int i = 1; i <= N; i++) {
        if (visited[i] == 0)
            GraphCheck(i);
    }
    
    cout << Cycle << " " << Bidirctional  << " " << Forward << endl;
    
    return 0;
}
