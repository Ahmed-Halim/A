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

void dfs (int node) {
    if (visited[node])
        return;
    visited[node] = true;
    cout << node << " ";
    for (auto i : adj[node]) {
        dfs(i);
    }
}

void bfs(int node) {
    queue<int> q;
    q.push(node);
    visited[node] = true;
    
    while (!q.empty()) {
        int front = q.front();
        q.pop();
        cout << front << " ";
        for (auto i : adj[front]) {
            if (visited[i] == false) {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

void connected () {
    for (int i = 1; i <= N; i++) {
        if (visited[i] == false) {
            dfs(i);
            cout << endl;
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
        adj[v].push_back(u);
    }

    dfs(1);
    bfs(1);
    connected();
    
    return 0;
}
