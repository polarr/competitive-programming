/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-09-11
 * Contest: 2008
 * Problem: F
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
    ll n; cin >> n;

    ll sum = 0;
    ll sqsum = 0;

    for (int i = 0; i < (int)n; i++){
        ll a; cin >> a;

        sum += a;
        sum %= MOD;

        sqsum += a * a;
        sqsum %= MOD;
    }

    sum *= sum;
    sum %= MOD;

    ll p = (sum - sqsum + MOD) % MOD;
    p *= mod_exp(2, MOD - 2, MOD);
    p %= MOD;
    ll q = mod_exp(n * (n - 1)/2, MOD - 2, MOD);

    cout << (p * q % MOD) << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for (int t = 1; t <= tc; ++t){
        // cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}