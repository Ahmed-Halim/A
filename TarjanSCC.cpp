#include <bits/stdc++.h>
using namespace std;

#define PI acos(-1)
#define EPS 1e-9
#define MOD 1e9+7
#define SET(a) memset(a , 0 , sizeof(a))
#define Fast ios_base::sync_with_stdio(false)

int N , E , u , v , numSCC , dfsNumberCounter;
vector <vector<int>> adj;
vector <int> visited , dfs_num , dfs_low , S , findSCC;

void TarjanSCC(int u) {
    dfs_low[u] = dfs_num[u] = ++dfsNumberCounter;
    S.push_back(u);
    visited[u] = 1;
    for (auto v : adj[u]) {
        if (dfs_num[v] == 0)
            TarjanSCC(v);
        if (visited[v])
            dfs_low[u] = min(dfs_low[u] , dfs_low[v]);
    }
    
    if (dfs_low[u] == dfs_num[u]) {
        numSCC++;
        while (1) {
            int v = S.back(); S.pop_back(); visited[v] = 0;
            cout << v;
            findSCC[v] = numSCC;
            if (u == v) break;
            cout << ", ";
        }
        cout << endl;
    }
}

int main() {
    Fast;
    cin >> N >> E;
    adj = vector <vector <int>> (N+1);
    findSCC = vector <int> (N+1);
    dfs_num = vector <int> (N+1);
    dfs_low.assign (N+1, 0);
    visited.assign (N+1 , 0);
    dfsNumberCounter = numSCC = 0;
    S.clear();
    
    for (int i = 0; i < E; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
    }
    
    for (int i = 1; i <= N; i++)
        if (dfs_num[i] == 0)
            TarjanSCC(i);
    
    cout << "Strong Connected Componnent : " << numSCC << endl;
    
    vector <bool> root (numSCC , true);
    for (int i = 1; i <= N; i++) {
        for (auto f : adj[i]) {
            if (findSCC[i] != findSCC[f]) {
                root[findSCC[f]]= false;
            }
        }
    }
    
    int disconnected = 0;
    for (int i = 1; i <= numSCC; i++) {
        if (root[i]) {
            disconnected++;
        }
    }
    cout << "Disconnected Nodes : " << disconnected << endl;
    
    return 0;
}
