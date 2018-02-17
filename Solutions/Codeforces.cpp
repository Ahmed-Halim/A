#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n , k , ans = 0 , o = 1 , Min = INT_MAX;
    
    cin >> n >> k;
    long long a[k];
    for (int i = 0; i < k; i++) {
        cin >> a[i];
        if (n%a[i] < Min) {
            Min =n%a[i];
            o = i+1;
            ans = n/a[i];
        }
    }
    cout << o << " " << ans;
    
    return 0;
}
