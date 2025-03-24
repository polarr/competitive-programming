/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-03-22
 * Contest: Codeforces 2090
 * Problem: D
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

void solve(){
    int n; cin >> n;

    if (n == 2){
        cout << "2 1" << endl;
        return;
    }
    
    int a = n/3;
    int p = 2 * a;
    rep(i, a, 2 * a + 1){
        if (!is_composite[i]){
            p = i;
            break;
        }
    }

    vi done(n + 1, 0);

    cout << p;

    done[p] = 1;

    rep(i, 1, a){
        done[p + i] = 1;
        done[p - i] = 1;
        cout << " " << p + i << " " << p - i;
    }

    rep(i, 1, n + 1){
        if (!done[i]){
            cout << " " << i;
        }
    }

    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    prime_sieve(MAX_N + 1);
    is_composite[1] = true;
    int tc;
    cin >> tc;
    for (int t = 1; t <= tc; ++t){
        // cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}