/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-12-29
 * Contest: 
 * Problem: F2
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

const int MAX_N = 6e5 + 1;
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

/** 
 * PRECOMPUTE: Factorials and Factorial Inverses
 * PURPOSE: Computes factorials and their inverses modulo m
 * REQUIRE: Modular Exponentiation
 * TIME: O(n + log m)
*/
vector<ll> fac(MAX_N + 1);
vector<ll> fac_inv(MAX_N + 1);
void factorial(ll p) {
	fac[0] = 1;
	for (int i = 1; i <= MAX_N; i++) { fac[i] = fac[i - 1] * i % p; }
}
void factorial_inverses(ll p) {
    fac_inv[0] = 1;
	fac_inv[MAX_N] = mod_exp(fac[MAX_N], p - 2, p);
	for (int i = MAX_N; i >= 1; i--) { fac_inv[i - 1] = fac_inv[i] * i % p; }
}

/** 
 * ALGORITHM: Binomial Coefficient
 * PURPOSE: Computes n choose r
 * CONSTRAINT: 0 <= n, r <= MAX_N
 * REQUIRE: Factorials and Factorial Inverses
 * TIME: O(1)
*/
ll choose(ll n, ll r, ll p) {
    if (r > n){
        return 0;
    }
	return fac[n] * fac_inv[r] % p * fac_inv[n - r] % p;
}


vl pw(61, 1);

void solve(){
    int n, m; cin >> n >> m;

    vi cnt(61, 0);
    rep(i, 0, n) {
        int x; cin >> x;
        cnt[x]++;
    }

    ll tot = n;

    rep(q, 0, m) {
        ll cs, x; cin >> cs >> x;
        if (cs == 1) {
            cnt[x]++;
            tot++;
        } else if (cs == 2) {
            cnt[x]--;
            tot--;
        } else {
            ll ans = 0;
            ll curr = 1;
            ll rem = tot;
            int run = 0, add = 0;
            for (int i = 60; i >= 0; i--) {
                bool bit = x & pw[i];

                if (bit) {
                    run++;
                } else {
                    int need = i + run + add;
                    ll win = mod_exp(2, cnt[need], MOD);
                    rep(j, 0, run + 1) {
                        win += MOD - choose(cnt[need], j, MOD);
                        win %= MOD;
                    }

                    rem -= cnt[need];

                    win *= curr;
                    win %= MOD;
                    win *= mod_exp(2, rem, MOD);
                    win %= MOD;

                    ans += win;
                    ans %= MOD;

                    curr *= choose(cnt[need], run, MOD);
                    curr %= MOD;

                    add += run;
                    run = 0;
                }
            }

            // cout << curr << endl;

            if (run > 0) {
                int need = -1 + run + add;
                ll win = mod_exp(2, cnt[need], MOD);
                rep(j, 0, run) {
                    win += MOD - choose(cnt[need], j, MOD);
                    win %= MOD;
                }

                rem -= cnt[need];

                win *= curr;
                win %= MOD;
                win *= mod_exp(2, rem, MOD);
                win %= MOD;

                ans += win;
                ans %= MOD;
            } else {
                ans += curr * mod_exp(2, rem, MOD) % MOD;
                ans %= MOD;
            }

            cout << ans << '\n';
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    factorial(MOD);
    factorial_inverses(MOD);

    rep(i, 1, 61) {
        pw[i] = pw[i - 1] * 2;
    }

    solve();
    return 0;
}