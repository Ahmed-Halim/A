#include <bits/stdc++.h>
using namespace std;

vector<long long> isprime(1000001 , true);
vector<long long> prime;
vector<long long> SPF(1000001);

void sieve () {
    int N = 1000001;
    isprime[0] = isprime[1] = false ;
    for (long long i = 2; i < N; i++) {
        if (isprime[i]) {
            prime.push_back(i);
            SPF[i] = i;
        }
        for (long long j = 0; j < prime.size() &&  i*prime[j] < N && prime[j] <= SPF[i]; j++) {
            isprime[i*prime[j]] = false;
            SPF[i*prime[j]] = prime[j];
        }
    }
}

vector<int> getFactorization(int x) {
    vector<int> ret;
    while (x != 1) {
        ret.push_back(SPF[x]);
        x = x / SPF[x];
    }
    return ret;
} 

vector <int> Types[1001];

int getType(int number) {
    vector <int> factors = getFactorization(number);
    for (int x = 1; x < factors.size(); x++) {
        if (factors[x] == factors[x-1])
            return -1;
    }
    return (int)factors.size();
}

int getMax(int l , int r, int type) {
    int idx = (upper_bound(Types[type].begin(), Types[type].end(), r)-Types[type].begin()-1);
    if (idx >= 0 && idx < Types[type].size())
        return Types[type][idx];
    return -1;
}

int main(){
    sieve();
    for (int i = 1; i <= 1000000; i++) {
        int type = getType(i);
        if (type != -1) {
            Types[type].push_back(i);
        }
    }
    int n , L, R, a, b;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int ans = 0;
        cin >> L >> R >> a >> b;
        for (int j = a; j <= b; j++) {
            ans = max(ans , getMax(L , R, j));
        }
        cout << ans << endl;
    }
    return 0;
}
