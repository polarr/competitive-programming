/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-07-22
 * Contest: 
 * Problem: D
**/

#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using pii = pair<int, int>;
#define pb push_back
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

const int MAX_N = 1e5 + 1;
const ll MOD = 998244353;

/** 
 * ALGORITHM: Modular Exponentiation 
 * PURPOSE: Computes x^n (mod m)
 * CONSTRAINT: m * m <= LLONG_MAX to prevent overflow
 * TIME: O(log n)
*/
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
    int n, m; cin >> n >> m;
    vector<vector<array<ll, 4>>> events(m + 1);
    rep(i, 0, n){
        ll l, r, p, q;
        cin >> l >> r >> p >> q;
        ll prob = p * mod_exp(q, MOD - 2, MOD) % MOD;
        prob %= MOD;
        events[l].pb({l, 1, r, prob});
        events[r].pb({r, 2, l, prob});
    }

    vl dp(m + 1, 0);
    dp[0] = 1;
    ll active = 1;
    vl activedp(m + 1, 1);
    rep(i, 1, m + 1){
        ll remove = 1;
        for (array<ll, 4> event : events[i]){
            if (event[1] == 1){
                active *= (1 + MOD - event[3]) % MOD;
                remove *= mod_exp((1 + MOD - event[3]), MOD - 2, MOD);
                remove %= MOD;
                active %= MOD;
            }
        }

        activedp[i] = activedp[i - 1] * remove % MOD;

        for (array<ll, 4> event : events[i]){
            if (event[1] == 2){
                ll prob = event[3];
                dp[i] += active * activedp[event[2] - 1] % MOD * prob % MOD * mod_exp(1 + MOD - prob, MOD - 2, MOD) % MOD * dp[event[2] - 1] % MOD;
                // cerr << event[2] << " " << active * activedp[event[2] - 1] % MOD * prob % MOD * mod_exp(1 + MOD - prob, MOD - 2, MOD) % MOD << endl;
                dp[i] %= MOD;
            }
        }
    }

    cout << dp[m] << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}