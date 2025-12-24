/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-12-24
 * Contest: Codeforces 2176
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

const int MAX_N = 2e5 + 1;
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
 * PRECOMPUTE: Mobius Linear Sieve
 * PURPOSE: Computes mu(k) up to MAX_N
 * REQUIRE: Prime Linear Sieve
 * TIME: O(n)
 */
vector<ll> mu(MAX_N + 1);
void mobius_sieve () {
	mu[1] = 1;
	for (ll i = 2; i < MAX_N + 1; ++i) {
		if (!is_composite[i]) {
			mu[i] = -1;
		}
		for (ll j = 0; j < prime.size() && i * prime[j] < MAX_N + 1; ++j) {
			if (i % prime[j] == 0) {
				mu[i * prime[j]] = 0;
				break;
			} else {
				mu[i * prime[j]] = -mu[i];
			}
		}
	}
}

vl rad(MAX_N);
vl w(MAX_N, 0);

void precomp(ll n) {
    ll ans = 1;
    ll orig = n;
    while (n > 1) {
        ll p = min_div[n];
        ans *= p;
        while (n % p == 0) {
            n /= p;
        }

        w[orig]++;
    }

    rad[orig] = ans;
}

void solve(){
    int n, k; cin >> n >> k;

    vl pw(13, 0);
    rep(i, 0, 13) {
        pw[i] = mod_exp(i, k, MOD);
    }

    vl cnt(n + 1, 0);
    rep(i, 0, n) {
        int x; cin >> x;
        cnt[rad[x]]++;
    }

    vector<vl> div(n + 1, vl(7, 0));
    rep(d, 1, n + 1) {
        for (int t = 1; t * d <= n; t++) {
            int omega = w[t * d];
            div[d][omega] += cnt[t * d];
        }
    }

    vector<vl> f(n + 1, vl(7, 0));
    rep(m, 1, n + 1) {
        rep(a, 0, 7) {
            rep(b, a, 7) {
                rep(d, 0, 7) {
                    if (a + b < d) {
                        break;
                    }

                    ll curr = 0;
                    if (a == b) {
                        curr = ((div[m][a] * (div[m][a] - 1)) / 2) % MOD;
                    } else {
                        curr = div[m][a] * div[m][b] % MOD;
                    }
                    
                    curr *= pw[a + b - d];
                    curr %= MOD;

                    f[m][d] += curr;
                    f[m][d] %= MOD;
                }
            }
        }
    }

    ll ans = 0;
    rep(d, 1, n + 1) {
        for (int t = 1; t * d <= n; t++) {
            ans += MOD + mu[t] * f[t * d][w[d]];
            ans %= MOD;
        }
    }

    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    prime_sieve(MAX_N);
    mobius_sieve();

    rep(i, 1, MAX_N) {
        precomp(i);
    }

    int tc;
    cin >> tc;
    for (int t = 1; t <= tc; ++t){
        // cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}