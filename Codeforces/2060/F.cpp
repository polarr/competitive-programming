/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-05-25
 * Contest: Codeforces 2060
 * Problem: F
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

vector<vl> dp(MAX_N, vl(30, 0));

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
 * PRECOMPUTE: Factorials and Factorial Inverses
 * PURPOSE: Computes factorials and their inverses modulo m
 * REQUIRE: Modular Exponentiation
 * TIME: O(n + log m)
*/
vector<ll> fac(MAX_N + 100 + 1);
vector<ll> fac_inv(MAX_N + 100 + 1);
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
    int k, n; cin >> k >> n;

    cout << n << " ";

    rep(x, 2, k + 1){
        ll ans = 0;
        ll c = n + 1;
        c %= MOD;
        rep(i, 1, min(30, n + 1)){
            c *= (n + 1 - i) % MOD;
            c %= MOD;
            c *= mod_exp(i + 1, MOD - 2, MOD);
            c %= MOD;
            ans += dp[x][i] * c % MOD;
            ans %= MOD;
        }

        cout << ans << " ";
    }

    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    prime_sieve(MAX_N);
    factorial(MOD);
    factorial_inverses(MOD);

    rep(x, 2, MAX_N){
        int xx = x;
        int p = min_div[xx];
        int a = 0;
        while (xx % p == 0){
            xx /= p;
            a++;
        }

        if (xx == 1){
            rep(i, 1, a + 1){
                dp[x][i] = choose(a - 1, i - 1, MOD);
            }
            continue;
        }

        int q = min_div[xx];
        int b = 0;
        while (xx % q == 0){
            xx /= q;
            b++;
        }

        if (a > b){
            swap(a, b);
            swap(p, q);
        }

        int d = x;

        rep(i, 0, a){
            d /= p;
        }

        rep(i, 1, 30){
            ll ans = 0;
            rep(j, 0, i){
                ans += choose(i, j, MOD) * choose(i + a - j - 1, i - 1, MOD) % MOD * dp[d][i - j] % MOD;
                ans %= MOD;
            }
            dp[x][i] = ans;
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