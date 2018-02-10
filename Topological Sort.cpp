#include <bits/stdc++.h>
using namespace std;

#define PI acos(-1)
#define EPS 1e-9
#define MOD 1e9+7
#define SET(a) memset(a , 0 , sizeof(a))
#define Fast ios_base::sync_with_stdio(false)

int N , E , u , v;
vector <vector <int>> adj;
bool visited[100005];
vector <int> TS;
vector <int> in_degree;

void TS_DFS (int node) {
    if (visited[node])
        return;
    visited[node] = true;
    for (auto i : adj[node]) {
        TS_DFS(i);
    }
    TS.push_back(node);
}

void TS_BFS() {
    in_degree = vector <int> (N+1, 0);
    for (int node = 1; node <= N; node++) {
        for (auto i : adj[node]) {
            in_degree[i]++;
        }
    }
    queue<int> q;
    for (int i = 1; i <= N; i++) {
        if (in_degree[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int front = q.front();
        q.pop();
        TS.push_back(front);
        for (auto i : adj[front]) {
            if (--in_degree[i] == 0) {
                q.push(i);
            }
        }
    }
    
}

int main(){
    Fast;
    
    cin >> N >> E;
    adj = vector <vector <int>> (N+1);
    
    for (int i = 0; i < E; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
    }
    
    //----------------DFS--------------------
    
    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            TS_DFS(i);
        }
    }
    
    reverse(TS.begin(), TS.end());
    
    for (auto i : TS) {
        cout << i << " ";
    }
    
    //----------------BFS--------------------
    
    TS_BFS();
    
    for (auto i : TS) {
        cout << i << " ";
    }
    
    return 0;
}
