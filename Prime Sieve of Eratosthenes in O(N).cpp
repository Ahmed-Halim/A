#include <bits/stdc++.h>
using namespace std;

#define PI acos(-1)
#define MOD 1e9+7
#define SET(a , x) memset(a , x , sizeof(a))
#define Fast ios_base::sync_with_stdio(false) , cin.tie(0) , cout.tie(0)

vector<long long> isprime(1000001 , true);
vector<long long> prime;
vector<long long> SPF(1000001);
bool P[100001];

void Prime (long long N) {
    isprime[0] = isprime[1] = false ;
    for (long long i = 2; i < N; i++) {
        if (isprime[i]) {
            prime.push_back(i);
            P[i] = true;
            SPF[i] = i;
        }
        for (long long j = 0; j < prime.size() &&  i*prime[j] < N && prime[j] <= SPF[i]; j++) {
            isprime[i*prime[j]] = false;
            SPF[i*prime[j]] = prime[j];
        }
    }
}

int main() {
    Fast;
    
    Prime(1000);
    
    for (auto i : prime) {
        cout << i << " ";
    }

    for (int i = 0; i <= 1000; i++) {
        if (P[i]) {
            cout << i << " ";
        }
    }
    
    return 0;
}
