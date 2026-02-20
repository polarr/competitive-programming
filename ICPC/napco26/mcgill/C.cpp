/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2026-02-16
 * Contest: 
 * Problem: C
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

vector<int> factor(int n){
    vector<int> ans;
	while(n != 1){
        int i = min_div[n];
		while (n % i == 0) {
			n /= i;
            ans.pb(i);
		}
	}

	return ans;
}

void solve(int n, int k){
    map<int, int> f;

    for (int x = n - k + 1; x <= n; x++) {
        vi d = factor(x);
        for (int p : d) {
            f[p]++;
        }
    }

    for (int x = 1; x <= k; x++) {
        vi d = factor(x);
        for (int p : d) {
            f[p]--;
        }
    }

    ll ans = 1;

    for (auto [p, c] : f) {
        ans *= (c + 1);
    }

    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    prime_sieve(MAX_N);

    int n, k;
    while (cin >> n >> k) {
        solve(n, k);
    }
    return 0;
}