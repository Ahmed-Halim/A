#include <bits/stdc++.h>
using namespace std;

int N , E , u , v , w , Start , L , K , ans = 0;
vector <pair<int, int>> adj[100005];
bool visited[100005];

void dfs (int prevNode , int nextNode , int Level , int Weight) {
    
    if (visited[nextNode] || Level > L) return;
    
    visited[nextNode] = true;
    
    cout << "(" << prevNode << " , " << nextNode << ") Level (" << Level << ") Weight(" << Weight << ")" << endl;
    
    for (auto i : adj[nextNode]) {
        int from = nextNode;
        int to = i.first;
        int w = i.second;
        dfs(from , to , Level+1 , w);
    }
    
    ans = max(ans , Weight);
    
    return;
}



int main(){
    cin >> N >> E >> Start >> L >> K;
    
    for (int i = 0; i < E; i++) {
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    
    dfs (Start , Start , 0 , 0);
    
    cout << "Max Weight in Levels <= L : " << ans << endl;
    
    return 0;
}


5 5 2 7 2
2 1 71
2 3 88
2 4 50
1 5 95
4 3 104

-----------------

9 8 5 3 1
1 5 3
4 5 6
3 4 2
3 7 17
7 9 10
4 2 7
2 6 23
6 8 70
