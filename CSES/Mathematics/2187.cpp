/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-04-04
 * Contest: CSES Problemset
 * Problem: 2187
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


const int MAX_N = 1e6;
const ll MOD = 1e9 + 7;

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
    factorial(MOD); factorial_inverses(MOD);
    ll n; cin >> n;
    ll a = 0;
    string s; cin >> s;
    ll k = s.size();
    rep(i, 0, k){
        if (s[i] == '('){
            a++;
        } else {
            a--;
        }

        if (a < 0){
            cout << 0 << endl;
            return;
        }
    }

    ll m = n - k;

    if (m < a || (m - a) % 2 == 1){
        cout << 0 << endl;
        return;
    }

    ll t = (m - a)/2;

    cout << choose(m, t, MOD) * (a + 1) % MOD * mod_exp(t + a + 1, MOD - 2, MOD) % MOD << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}