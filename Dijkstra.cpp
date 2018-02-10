#include <bits/stdc++.h>
using namespace std;

#define PI acos(-1)
#define EPS 1e-9
#define MOD 1e9+7
#define SET(a , x) memset(a , x , sizeof(a))
#define Fast ios_base::sync_with_stdio(false)

int N , E , u , v , w;
vector <pair<int, int>> adj[100005];
int node[100005];

void Path(int from , int to) {
    if (to != from)
        Path(from , node[to]);
    cout << to << " ";
}

void Dijkstra (int src , int distnation) {
    priority_queue< pair<int, int>, vector <pair<int, int>> , greater<pair<int, int>> > pq;
    vector<unsigned long long> dist(N+1, LONG_LONG_MAX);
    pq.push({0 , src});
    dist[src] = 0;
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        for (auto i : adj[u]) {
            int v = (i).first;
            int weight = (i).second;
            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
                node[v] = u;
            }
        }
    }
    if (dist[distnation] == LONG_LONG_MAX) {
        cout << -1 << endl;
    } else {
        cout << dist[distnation] << endl;
        Path(src, distnation);
    }
}

int main(){
    Fast;
    
    cin >> N >> E;
    
    for (int i = 0; i < E; i++) {
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    
    
    Dijkstra (1 , N);
    return 0;
}
