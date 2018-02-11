#include <bits/stdc++.h>
using namespace std;

#define PI acos(-1)
#define EPS 1e-9
#define MOD 1e9+7
#define SET(a) memset(a , 0 , sizeof(a))
#define Fast ios_base::sync_with_stdio(false)

int N , E , u , v , *disc , *low , *parent;
vector <vector <int>> adj;
bool *visited , *ap;

void Articulation (int u) {
    static int time = 0;
    int children = 0;
    visited[u] = true;
    disc[u] = low[u] = ++time;
    for (auto v : adj[u]) {
        if (!visited[v]) {
            children++;
            parent[v] = u;
            Articulation(v);
            low[u]  = min(low[u], low[v]);
            if (parent[u] == -1 && children > 1)
                ap[u] = true;
            if (parent[u] != -1 && low[v] >= disc[u])
                ap[u] = true;
        }
        else if (v != parent[u]) {
            low[u]  = min(low[u], disc[v]);
        }
    }
}

int main(){
    Fast;
    
    cin >> N >> E;
    adj = vector <vector <int>> (N+1);
    visited = new bool[N+1];
    disc = new int[N+1];
    low = new int[N+1];
    parent = new int[N+1];
    ap = new bool[N+1];
    
    for (int i = 1; i <= E; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    
    for (int node = 1; node <= N; node++) {
        parent[node] = -1;
        visited[node] = false;
        ap[node] = false;
    }
    
    for (int node = 1; node <= N; node++) {
        if (!visited[node]) {
            Articulation(node);
        }
    }
    
    for (int node = 1; node <= N; node++) {
        if (ap[node]) {
            cout << node << " ";
        }
    }
    
    return 0;
}
