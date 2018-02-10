#include <bits/stdc++.h>
using namespace std;

#define PI acos(-1)
#define MOD 1e9+7
#define SET(a , x) memset(a , x , sizeof(a))
#define Fast ios_base::sync_with_stdio(false) , cin.tie(0) , cout.tie(0)

int n , row , col;
char a[100][100];
bool visited[100][100];

int dx[] = { 1, 0, -1, 0, 1, -1, 1, -1 };
int dy[] = { 0, 1, 0, -1, 1, 1, -1, -1 };

bool valid (int i , int j) {
    return (i >= 0 && i < n && j >= 0 && j < n) ? 1 : 0;
}

void floodfill(int i , int j) {
    visited[i][j] = true;
    for (int k = 0; k < 8; k++) {
        row = i + dx[k];
        col = j + dy[k];
        if (valid(row , col)) {
            if (!visited[row][col])
                floodfill(row , col);
        }
    }
}
int main(){
    Fast;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j])
                floodfill(i , j);
        }
    }
    
    return 0;
}
