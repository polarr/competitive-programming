/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-09-13
 * Contest: Codeforces 2148
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

const int MAX_N = 2e5 + 1;
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

vector<bool> consider(MAX_N, false);
vi mn(MAX_N, 1e9);
vi d(MAX_N, 0);
vi noncount(MAX_N, 0);

void solve(){
    int n; cin >> n;

    int ans = 0;

    vi maybe, pool;
    rep(i, 0, n){
        int a; cin >> a;
        int aa = a;

        while (a > 1){
            int p = min_div[a];
            d[p]++;

            pool.pb(p);

            if (i == 0){
                maybe.pb(p);
                consider[p] = true;
            }

            int c = 0;
            while (a % p == 0){
                c++;
                a /= p;
            }

            if (consider[p]){
                if (mn[p] > c){
                    noncount[p] = i;
                    mn[p] = c;
                } else if (mn[p] < c){
                    noncount[p]++;
                }

                ans = max(ans, noncount[p]);
            } else {
                ans = max(ans, d[p]);
            }
        }

        for (int p : maybe){
            if (aa % p != 0){
                ans = max(ans, d[p]);
                consider[p] = false;
            }
        }

        cout << ans << " ";
    }


    for (int p : pool){
        mn[p] = 1e9;
        d[p] = 0;
        noncount[p] = 0;
    }

    for (int p : maybe){
        consider[p] = false;
    }

    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    prime_sieve(MAX_N);
    int tc;
    cin >> tc;
    for (int t = 1; t <= tc; ++t){
        // cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}