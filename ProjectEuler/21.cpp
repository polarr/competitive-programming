/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-09-21
 * Contest: Project Euler
 * Problem: 21
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
const ll MOD = 1e9 + 7;

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

vi to(MAX_N, -1);

ll prod = 1;
ll ans = 0;
vector<pii> factors;

void rec(int i){
    if (i == factors.size()){
        ans += prod;
        return;
    }

    auto &[p, c] = factors[i];
    rep(j, 0, c + 1){
        rec(i + 1);
        if (j != c) prod *= p;
    }

    rep(j, 0, c){
        prod /= p;
    }
}

void solve(){
    rep(i, 2, MAX_N){
        ans = 0;
        factors = {};
        int x = i;
        while (x > 1){
            int p = min_div[x];
            int c = 0;
            while (x % p == 0){
                x /= p;
                c++;
            }

            factors.pb({p, c});
        }

        rec(0);
        to[i] = ans - i;
    }

    vector<bool> visited(MAX_N, false);

    int mx = 0, ans = 0;

    rep(i, 2, 1e4){
        if (i != to[i] && i == to[to[i]]){
            ans += i;
        }
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