/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-12-27
 * Contest: CSES Problemset
 * Problem: 2182
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

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

void solve(){
    int n; cin >> n;

    ll num = 1; 
    ll nm = 1;
    ll sum = 1;
    ll prod = 1;

    for (int i = 0; i < n; i++){
        ll x, k; cin >> x >> k;

        num *= k + 1;
        num %= MOD;

        sum *= (mod_exp(x, k + 1, MOD) - 1) % MOD;
        sum %= MOD;
        sum *= mod_exp(x - 1, MOD - 2, MOD);
        sum %= MOD;

        prod = mod_exp(prod, (k + 1) % (MOD - 1), MOD);
        prod *= mod_exp(mod_exp(x, k * (k + 1)/2 % (MOD - 1), MOD), nm, MOD);
        prod %= MOD;

        nm *= k + 1;
        nm %= MOD - 1;
    }

    cout << num << " " << sum << " " << prod << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}