/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-12-27
 * Contest: CSES Problemset - Mathematics
 * Problem: 1716
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

vector<ll> fact(10e6 + 1, 1);

ll mod_exp(ll x, ll n, ll m) {
	x %= m;

	ll res = 1;
	while (n > 0) {
		if (n % 2 == 1) { res = res * x % m; }
		x = x * x % m;
		n /= 2;
	}

	return res;
}

ll choose(ll n, ll k){
    return (((fact[n] * mod_exp(fact[k], MOD - 2, MOD)) % MOD) * mod_exp(fact[n - k], MOD - 2, MOD)) % MOD;
}

void solve(){
    for (int i = 2; i < fact.size(); i++){
        fact[i] = i * fact[i - 1];
        fact[i] %= MOD;
    }

    ll n, m; cin >> n >> m;

    cout << choose(n + m - 1, n - 1) << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}