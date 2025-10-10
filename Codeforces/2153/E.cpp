/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-10-10
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

vector<bool> already(MAX_N + 1, false);

ll calc(ll num, ll p){
    ll curr = p;
    ll ans = 0;
    while (curr <= num){
        ans += num/curr;
        curr *= p;
    }

    return ans;
}

void solve(){
    ll n, m; cin >> n >> m;
    ll ans = 0;
    vl maybe;

    if (!is_composite[n]){
        cout << 0 << endl;
        return;
    }

    ll num = n;
    while (num > 1){
        ll p = min_div[num];
        if (!already[p]){
            maybe.pb(p);
            already[p] = true;
        }

        while (num % p == 0){
            num /= p;
        }
    }

    for (ll x = n - 1; x >= 1; x--){
        ll num = x;
        while (num > 1){
            ll p = min_div[num];
            if (!already[p]){
                maybe.pb(p);
                already[p] = true;
            }

            while (num % p == 0){
                num /= p;
            }
        }

        ll mn = 1e15;

        for (ll p : maybe){
            ll a = calc(x, p);
            ll b = calc(n, p);

            ll pw = p;
            ll d = 1;
            while (pw <= m){
                ll ad = a/d;
                ll bd = b/d;
                if (ad != bd){
                    mn = min(mn, ad);
                }

                pw *= p;
                d++;
            }
        }

        ans += mn;

        if (!is_composite[x]){
            break;
        }
    }

    for (ll p : maybe){
        already[p] = false;
    }

    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    prime_sieve(MAX_N + 1);
    int tc;
    cin >> tc;
    for (int t = 1; t <= tc; ++t){
        // cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}