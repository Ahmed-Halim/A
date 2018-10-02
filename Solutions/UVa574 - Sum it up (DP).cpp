#include <bits/stdc++.h>
using namespace std;

#define MX 200001
#define pb push_back
#define all(x) x.begin(), x.end()
#define LB(x , value) *lower_bound(all(x) , value)
#define UB(x , value) *upper_bound(all(x) , value)
#define mem(a  , value) memset(a , value , sizeof(a))
#define LBP(x , value) (lower_bound(all(x) , value)-x.begin())
#define UBP(x , value) (upper_bound(all(x) , value)-x.begin())
#define Fast ios_base::sync_with_stdio(false) , cin.tie(0) , cout.tie(0)

int T = 1 , t , n, a[100];
vector <vector<int>> ans;

void solve (int i , int prev , int sum, vector<int> cur) {
    if (sum == t) {
        sort(cur.begin() , cur.end() , greater<int>());
        ans.push_back(cur);
        return;
    }
    if (i == n) return;
    
    solve(i+1 , prev , sum , cur);
    cur.push_back(a[i]);
    solve(i+1 , i , sum+a[i], cur);
    
}

int main(){
    Fast;
    while (true) {
        cin >> t >> n;
        if (t == 0 || n == 0) break;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        vector <int> temp;
        solve(0 , -1 , 0 , temp);
        
        sort(ans.begin() , ans.end());
        ans.erase(unique(ans.begin(), ans.end() ), ans.end());
        
        cout << "Sums of "<<t<<":" << endl;
        if (ans.size() == 0)
            cout << "NONE" << endl;
        
        for (auto i = ans.rbegin(); i < ans.rend(); i++) {
            string x = "";
            for (auto j : *i) {
                x += to_string(j) + "+";
            }
            cout << x.substr(0 , x.size()-1) << endl;
        }
        ans.clear();
    }
    
    return 0;
}
