/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2026-02-20
 * Contest: 
 * Problem: H
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

const int MAX_N = 4e6 + 1;
const ll MOD = 10000003233;

vl primes = {3, 11, 101, 3000301};

vector<vl> fac(4, vl(MAX_N + 1));
vector<vl> fac_inv(4, vl(MAX_N + 1));

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
void factorial(vl &fac, ll p) {
	fac[0] = 1;
	for (int i = 1; i <= MAX_N; i++) { fac[i] = fac[i - 1] * i % p; }
}
void factorial_inverses(vl &fac, vl& fac_inv, ll p) {
    fac_inv[0] = 1;
	fac_inv[p - 1] = mod_exp(fac[p - 1], p - 2, p);
	for (int i = p - 1; i >= 1; i--) { fac_inv[i - 1] = fac_inv[i] * i % p; }
}

/** 
 * ALGORITHM: Binomial Coefficient
 * PURPOSE: Computes n choose r
 * CONSTRAINT: 0 <= n, r <= MAX_N
 * REQUIRE: Factorials and Factorial Inverses
 * TIME: O(1)
*/
ll choose(ll n, ll r, int i) {
    ll p = primes[i];

    if (r > n){
        return 0;
    }
	return fac[i][n] * fac_inv[i][r] % p * fac_inv[i][n - r] % p;
}

ll bigchoose(ll n, ll r, int i) {
    ll p = primes[i];

    if (r > n){
        return 0;
    }

    ll ans = 1;
    while (n > 0 || r > 0) {
        ans *= choose(n % p, r % p, i);
        ans %= p;
        n /= p;
        r /= p;
    }

    return ans;
}

ll euclid(ll a, ll b, ll &x, ll &y){
    if (!b) return x = 1, y = 0, a;
    ll d = euclid(b, a % b, y, x);
    return y -= a/b * x, d;
}
    
ll crt(ll a, ll m, ll b, ll n){
    if (n > m) swap(a, b), swap(m, n);
    ll x, y, g = euclid(m, n, x, y);
    if ((a - b) % g != 0){
        return LLONG_MAX;
    }
    x = (b - a) % n * x % n / g * m + a;
    return x < 0 ? x + m * n / g : x; 
}

void solve(){
    ll n, k, c; cin >> n >> k >> c;
    --n; --c;

    vector<pair<ll, ll>> d;
    rep(i, 0, sz(primes)) {
        d.pb({bigchoose(n, c, i), primes[i]});
    }

    pair<ll, ll> curr = d[0];
    rep(i, 1, sz(primes)) {
        curr = {crt(curr.first, curr.second, d[i].first, d[i].second), primes[i] * curr.second};
    }

    cout << curr.first * 2 % MOD << '\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    rep(i, 0, sz(primes)) {
        factorial(fac[i], primes[i]);
        factorial_inverses(fac[i], fac_inv[i], primes[i]);
    }

    int tc;
    cin >> tc;
    for (int t = 1; t <= tc; ++t){
        // cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}