/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-11-29
 * Contest: UCup Zhengzhou
 * Problem: I
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

void solve(){
    ll n, k; cin >> n >> k;

    vl dp(k + 1, 1);
    vl pw(k + 1, 1);
    rep(i, 1, k + 1) {
        pw[i] = pw[i - 1] * (n - 1) % MOD;
    }

    rep(i, 1, n) {
        ll c = 1;
        rep(j, 0, k + 1) {
            if (j > 0) {
                c *= i;
                c %= MOD;
            }
            dp[j] *= (c + 1) % MOD;
            dp[j] %= MOD;
        }
    }

    ll tot = fac[n];

    ll ans = 0;
    rep(i, 1, k + 1) {
        ll c = 1;
        c *= mod_exp(tot, k - i, MOD);
        c %= MOD;
        c *= choose(k, i, MOD);
        c %= MOD;
        c *= dp[i];
        c %= MOD;

        if (i % 2 == 0) {
            c = MOD - c;
            c %= MOD;
        }

        ans += c;
        ans %= MOD;
    }

    // cout << ans << endl;
    
    ans *= mod_exp(tot, MOD - 1 - k, MOD);
    ans %= MOD;

    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    factorial(MOD);
    factorial_inverses(MOD);

    solve();
    return 0;
}