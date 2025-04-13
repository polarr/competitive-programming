/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-04-13
 * Contest: ICPC Practice Kattis pacnw24d1open
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

ll RT = 1e4;

void solve(){
    prime_sieve(MAX_N);
    vl d(MAX_N, 0);
    
    ll n; cin >> n;
    rep(i, 0, n){
        ll a; cin >> a;
        
        vi sq;
        ll x = a;
        for (ll p : prime){
            if (p > RT){
                break;
            }

            int c = 0;
            while (x % p == 0){
                x /= p;
                c++;
            }

            if (c > 1){
                sq.pb(p);
            }
        }

        ll p = sqrt(x);
        if (p != 1 && p * p == x){
            sq.pb(p);
        }

        int t = sq.size();

        rep(i, 0, (1 << t)){
            int div = 1;
            rep(j, 0, t){
                if (i & (1 << j)){
                    div *= sq[j];
                }
            }

            d[div]++;
        }
    }

    ll ans = n * (n - 1)/2;

    rep(i, 2, MAX_N){
        int x = i;
        bool good = true;
        ll par = 1;
        while (x != 1){
            int p = min_div[x];
            par = -par;
            int c = 0;
            while (x % p == 0){
                x /= p;
                c++;
            }

            if (c != 1){
                good = false;
                break;
            }
        }

        if (!good) continue;

        ans += par * d[i] * (d[i] - 1)/2;
    }

    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}