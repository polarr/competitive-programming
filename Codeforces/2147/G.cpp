/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-09-29
 * Contest: Codeforces 2147
 * Problem: G
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

const int MAX_N = 1e6 + 1;
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
 * PRECOMPUTE: Prime Linear Sieve
 * PURPOSE: Classifies numbers up to MAX_N as primes or not
 * TIME: O(n)
 */
vector<ll> prime;
vector<bool> is_composite(MAX_N + 1, false);
vector<ll> min_div(MAX_N + 1, 1);
void prime_sieve (ll n) {
	for (ll i = 2; i < n; ++i) {
		if (!is_composite[i]) {
			prime.pb(i);
            min_div[i] = i;
		}
		for (ll j = 0; j < prime.size() && i * prime[j] < n; ++j) {
			is_composite[i * prime[j]] = true;
            min_div[i * prime[j]] = prime[j];
			if (i % prime[j] == 0) {
				break;
			}
		}
	}
}

/**
 * PRECOMPUTE: Phi Linear Sieve
 * PURPOSE: Computes phi(k) up to MAX_N
 * REQUIRE: Prime Linear Sieve
 * TIME: O(n)
 */
vector<ll> phi(MAX_N + 1);
void phi_sieve () {
	phi[1] = 1;
	for (ll i = 2; i < MAX_N + 1; ++i) {
		if (!is_composite[i]) {
			phi[i] = i - 1;
		}
		for (ll j = 0; j < prime.size() && i * prime[j] < MAX_N + 1; ++j) {
			if (i % prime[j] == 0) {
				phi[i * prime[j]] = phi[i] * prime[j];
				break;
			} else {
				phi[i * prime[j]] = phi[i] * phi[prime[j]];
			}
		}
	}
}

// Radical
ll rad[MAX_N + 1];

void solve(){
    ll x, y, z; cin >> x >> y >> z;

    ll m = x * y * z;
    ll ans = mod_exp(m, MOD - 2, MOD);

    vl mps;
    while (x > 1){
        ll p = min_div[x];
        mps.pb(p);
        while (x % p == 0){
            x /= p;
        }
    }
    while (y > 1){
        ll p = min_div[y];
        mps.pb(p);
        while (y % p == 0){
            y /= p;
        }
    }
    while (z > 1){
        ll p = min_div[z];
        mps.pb(p);
        while (z % p == 0){
            z /= p;
        }
    }

    // BEAUTIFUL
    map<ll, int> ps;
    sort(all(mps));
    rep(i, 0, sz(mps)){
        if (i == 0 || mps[i] != mps[i - 1]){
            ll x = mps[i] - 1;
            while (x > 1){
                ll p = min_div[x];
                int a = 0;
                while (x % p == 0) {
                    x /= p;
                    a++;
                }

                if (gcd(p, m % p) == 1){
                    ps[p] += a;
                }
            }
        }
    }

    for (auto &[p, a] : ps){
        ll prod = MOD - 1;

        prod += mod_exp(p, a, MOD);
        prod %= MOD;
        prod *= mod_exp(p, MOD - 2, MOD);
        prod %= MOD;
        prod++;
        prod %= MOD;

        ans *= prod;
        ans %= MOD;
    }

    cout << ans << endl;

    /**
     * CRT Decomposition, too slow
     
    using T = pair<ll, ll>;

    vector<T> c;
    c.pb({1, 1});
    rep(i, 0, sz(ps)){
        ll t = ps[i] - 1;
        vector<T> curr, nc;
        rep(j, 1, (int)sqrt(t) + 1){
            if (t % j != 0) continue;
            ll x = j;
            if (gcd(x, m % x) == 1) curr.pb({phi[x], rad[x]});
            x = t/j;
            if (x == j) continue;
            if (gcd(x, m % x) == 1) curr.pb({phi[x], rad[x]});
        }

        for (T a : curr){
            for (T b : c){
                nc.pb({a.first * b.first % MOD, lcm(a.second, b.second)});
            }
        }

        c.swap(nc);
    }

    ll add = 0;
    for (T a : c){
        // cerr << a.first << "/" << a.second << " ";
        add += a.first * mod_exp(a.second, MOD - 2, MOD) % MOD;
        add %= MOD;
    }
    // cerr << endl;

    ans *= add;
    ans %= MOD;
     */
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    prime_sieve(MAX_N + 1);
    phi_sieve();

    rep(i, 1, MAX_N + 1){
        rad[i] = 1;
        int x = i;
        while (x > 1){
            int p = min_div[x];
            rad[i] *= p;
            while (x % p == 0) x /= p;
        }
    }

    int tc;
    cin >> tc;
    for (int t = 1; t <= tc; ++t){
        // cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}