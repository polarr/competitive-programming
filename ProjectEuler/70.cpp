/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-09-20
 * Contest: Project Euler
 * Problem: 70
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

const int MAX_N = 1e7 + 1;
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

void solve(){
    double mn = 1e9;
    int ans = 0;
    rep(xx, 2, MAX_N){
        int x = xx, y = phi[x];
        vi digits(10, 0);
        while (x > 0){
            digits[x % 10]++;
            x /= 10;
        }

        while (y > 0){
            digits[y % 10]--;
            y /= 10;
        }

        bool perm = true;

        rep(i, 0, 10){
            if (digits[i] != 0){
                perm = false;
                break;
            }
        }

        if (!perm) continue;
        if ((double) xx < (double) phi[xx] * mn){
            mn = (double) xx/phi[xx];
            ans = xx;
        }
    }

    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    prime_sieve(MAX_N);
    phi_sieve();

    solve();
    return 0;
}