/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-09-30
 * Contest: Project Euler
 * Problem: 193
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

const int MAX_N = (1 << 25);
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

void solve(){
    ll ans = 0;
    ll n = 1LL << 50;
    n--;

    for (ll d = 1; d < (ll)sqrt(n) + 1; d++){
        ll num = n/(d * d);
        ans += mu[d] * num;
    }

    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    prime_sieve(MAX_N + 1);
    mobius_sieve();
    solve();
    return 0;
}