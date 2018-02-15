#include <bits/stdc++.h>
using namespace std;

#define PI acos(-1)
#define MOD 1e9+7
#define SET(a , x) memset(a , x , sizeof(a))
#define Fast ios_base::sync_with_stdio(false) , cin.tie(0) , cout.tie(0)

int main(){
    Fast;
    string x;
    cin >> x;
    cout << x;
    
    for (int i = x.size()-2; i >= 0; i--) {
        cout << x[i];
    }
    
    return 0;
}
