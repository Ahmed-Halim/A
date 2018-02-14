#include <bits/stdc++.h>
using namespace std;

#define PI acos(-1)
#define MOD 1e9+7
#define SET(a , x) memset(a , x , sizeof(a))
#define Fast ios_base::sync_with_stdio(false) , cin.tie(0) , cout.tie(0)

int main(){
    Fast;
    long long n , m;
    cin >> n >> m;
    long long a[n] , b[m];
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    long long Max = -LONG_LONG_MAX , Index;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i]*b[j] > Max) {
                Max = a[i]*b[j] ;
                Index = i;
            }
        }
    }
    
    Max = -LONG_LONG_MAX;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i != Index && a[i]*b[j] > Max) {
                Max = a[i]*b[j] ;
            }
        }
    }
    cout << Max;
    return 0;
}
