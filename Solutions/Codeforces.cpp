#include <bits/stdc++.h>
using namespace std;

int main(){
    int n , x = 0 , y = 0 , ans = 0;
    string dir;
    cin >> n;
    cin >> dir;
    for (int i = 0; i < n; i++) {
        if (dir[i] == 'U') {
            x++;
        }
        if (dir[i] == 'R') {
            y++;
        }
        
        if (x == y && dir[i] == dir[i+1]) {
            ans++;
        }
    }
    cout << ans;
    return 0;
}
