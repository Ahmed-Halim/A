#include <bits/stdc++.h>
using namespace std;

#define PI acos(-1)
#define MOD 1e9+7
#define SET(arr , x) memset(arr , x , sizeof(a))
#define Fast ios_base::sync_with_stdio(false) , cin.tie(0) , cout.tie(0)

int fib[100005];

void Fibonacci (int n) {
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i <= n; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }
}

int main(){
    Fast;
    int n;
    cin >> n;
    Fibonacci(n);
    
    cout << fib[n];
    
    return 0;
}
