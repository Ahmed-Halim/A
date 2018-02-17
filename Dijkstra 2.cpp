#include <bits/stdc++.h>
using namespace std;

#define PI acos(-1)
#define MOD 1e9+7
#define SET(a , x) memset(a , x , sizeof(a))
#define Fast ios_base::sync_with_stdio(false) , cin.tie(0) , cout.tie(0)

int N , E;
vector<vector< pair <int, long long>>> Adj;
vector<unsigned long long> dist;

void Dijkstra () {
    priority_queue< pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    for(int i = 0 ; i < N; i++)
        pq.push({ dist[i] , i });
    while (!pq.empty()) {
        pair<long long, int> front = pq.top(); pq.pop();
        long long d = front.first;
        int u = front.second;
        if (d > dist[u]) continue;
        for (auto j : Adj[u]) {
            pair<int, long long> v = j;
            if (dist[u] + v.second < dist[v.first]) {
                dist[v.first] = dist[u] + v.second;
                pq.push({ dist[v.first] , v.first });
            }
        }
    }
}

int main() {
    cin >> N >> E;
    Adj = vector <vector <pair<int, long long>>> (N);
    dist = vector <unsigned long long> (N);
    
    for (int i = 0 ; i < E; i++){
        int u, v; long long w;
        cin >> u >> v >> w;
        u--, v--;
        Adj[u].push_back({ v , w+w });
        Adj[v].push_back({ u , w+w });
    }
    
    for (int i = 0 ; i < N; i++)
        cin >> dist[i];
    
    Dijkstra();
    
    for (int i = 0 ; i < N; i++)
        cout << dist[i] << " ";
    
    return 0;
}
