/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-11-18
 * Contest: CSES Problemset
 * Problem: 3398
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

void solve(){
    int n; cin >> n;

    vi p(n);
    rep(i, 0, n){
        cin >> p[i];
        --p[i];
    }

    vector<bool> visited(n, false);

    vi factor(MAX_N, 0);
    vi cycles;
    rep(i, 0, n){
        if (visited[i]) continue;
        visited[i] = true;
        int curr = i;
        int len = 1;
        while (p[curr] != i){
            curr = p[curr];
            visited[curr] = true;
            len++;
        }

        cycles.pb(len);
    }

    for (int x : cycles){
        int y = x;
        while (y > 1){
            int p = min_div[y];
            int a = 0;
            while (y % p == 0){
                a++;
                y /= p;
            }

            factor[p] = max(factor[p], a);
        }
    }

    ll ans = 1;
    rep(x, 0, MAX_N){
        int c = factor[x];
        if (c == 0) continue;
        ans *= mod_exp(x, c, MOD);
        ans %= MOD;
    }

    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    prime_sieve(MAX_N);
    solve();
    return 0;
}