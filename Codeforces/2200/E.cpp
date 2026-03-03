/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2026-03-02
 * Contest: 
 * Problem: E
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

void solve(){
    int n; cin >> n;

    vi arr(n);
    rep(i, 0, n) {
        cin >> arr[i];
    }

    bool notbob = false;
    rep(i, 1, n) {
        if (arr[i] < arr[i - 1]) {
            notbob = true;
        }
    }

    if (!notbob) {
        cout << "Bob" << endl;
        return;
    }

    rep(i, 0, n) {
        int x = arr[i];
        int q = -1;
        while (x > 1) {
            int p = min_div[x];
            if (q != -1) {
                cout << "Alice" << endl;
                return;
            }

            q = p;
            while (x % p == 0) {
                x /= p;
            }
        }

        arr[i] = q;
    }

    rep(i, 1, n) {
        if (arr[i] < arr[i - 1]) {
            cout << "Alice" << endl;
            return;
        }
    }

    cout << "Bob" << endl;
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