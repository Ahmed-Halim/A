#include <bits/stdc++.h>
using namespace std;

#define PI acos(-1)
#define MOD 1e9+7
#define SET(a , x) memset(a , x , sizeof(a))
#define Fast ios_base::sync_with_stdio(false) , cin.tie(0) , cout.tie(0)

int Sum (int num) {
    int sum = 1;
    while (num) {
        sum *= num%10 == 0 ? 1 : num%10;
        num /= 10;
    }
    if (sum >= 10) return Sum(sum);
    return sum;
}
int main(){
    Fast;
    map <int , vector <int>> mp;
    for (int i = 1; i <= 1000000; i++) {
        int temp = Sum(i);
        if (temp >= 1 && temp <= 9) {
            mp[temp].push_back(i);
        }
    }
    
 
    
    int Q , l , r , k , count = 0;
    cin >> Q;
    
    for (int i = 0; i < Q; i++) {
        cin >> l >> r >> k;
        vector<int>::iterator lower,up;
        low=std::lower_bound (mp[k].begin(), mp[k].end(), l);
        up= std::upper_bound (mp[k].begin(), mp[k].end(), r);
        cout << up - lower << endl;
    }
    
    
    return 0;
}
