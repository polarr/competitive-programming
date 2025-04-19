/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-04-19
 * Contest: ICPC Practice Codeforces 1938
 * Problem: F
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
    
    vl skill(n);
    rep(i, 0, n){
        cin >> skill[i];
    }

    ll a = skill[0];

    vi ps;
    int x = n;
    while (x != 1){
        int p = min_div[x];
        while (x % p == 0){
            x /= p;
        }

        ps.pb(p);
    }

    pair<ll, ll> ans = {INT_MAX, 1};

    // only need to check p groups, or groups with size n/p
    for (int p : ps){
        int x = p;

        vl group(x, 0);

        rep(i, 0, n){
            int j = i % x;
            group[j] += skill[i];
        }

        multiset<ll> vals;

        rep(i, 0, x){
            vals.insert(group[i]);
        }

        ll mx = *prev(vals.end());
        ll mn = *vals.begin();

        if (ans.first * mn > ans.second * mx){
            ans = {mx, mn};
        }

        rep(i, 1, n){
            int j = (i - 1) % x;
            int jj = i % x;

            vals.erase(vals.find(group[j]));
            vals.erase(vals.find(group[jj]));

            group[j] += skill[i] - a;
            group[jj] += a - skill[i];

            vals.insert(group[j]);
            vals.insert(group[jj]);

            ll mx = *prev(vals.end());
            ll mn = *vals.begin();

            if (ans.first * mn > ans.second * mx){
                ans = {mx, mn};
            }
        }
    }

    ll g = gcd(ans.first, ans.second);

    cout << ans.first/g << " " << ans.second/g << endl;
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