/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-11-05
 * Contest: Codeforces 2161
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

const int MAX_N = 1e5 + 1;
const ll MOD = 998244353;

/** 
 * ALGORITHM: Modular Exponentiation 
 * PURPOSE: Computes x^n (mod m)
 * CONSTRAINT: m * m <= LLONG_MAX to prevent overflow
 * TIME: O(log n)
*/
ll mod_exp(ll x, ll n, ll m) {
	x %= m;

	ll res = 1;
	while (n > 0) {
		if (n % 2 == 1) { res = res * x % m; }
		x = x * x % m;
		n /= 2;
	}

	return res;
}

/** 
 * PRECOMPUTE: Factorials and Factorial Inverses
 * PURPOSE: Computes factorials and their inverses modulo m
 * REQUIRE: Modular Exponentiation
 * TIME: O(n + log m)
*/
vector<ll> fac(MAX_N + 1);
vector<ll> fac_inv(MAX_N + 1);
void factorial(ll p) {
	fac[0] = 1;
	for (int i = 1; i <= MAX_N; i++) { fac[i] = fac[i - 1] * i % p; }
}
void factorial_inverses(ll p) {
    fac_inv[0] = 1;
	fac_inv[MAX_N] = mod_exp(fac[MAX_N], p - 2, p);
	for (int i = MAX_N; i >= 1; i--) { fac_inv[i - 1] = fac_inv[i] * i % p; }
}

/** 
 * ALGORITHM: Binomial Coefficient
 * PURPOSE: Computes n choose r
 * CONSTRAINT: 0 <= n, r <= MAX_N
 * REQUIRE: Factorials and Factorial Inverses
 * TIME: O(1)
*/
ll choose(ll n, ll r, ll p) {
    if (r > n){
        return 0;
    }
	return fac[n] * fac_inv[r] % p * fac_inv[n - r] % p;
}

void solve(){
    int n, k; cin >> n >> k;

    vi arr(n, -1);
    rep(i, 0, n){
        char s; cin >> s;
        if (s == '?'){
            continue;
        }

        arr[i] = s - '0';
    }

    vector<pii> cnt(n + 1, {0, 0});
    rep(i, 0, n){
        cnt[i + 1] = cnt[i];
        if (arr[i] == 0){
            cnt[i + 1].first++;
        } else if (arr[i] == 1){
            cnt[i + 1].second++;
        }
    }

    int kk = k - 1;

    vi mp(kk, -1);
    int zero = 0, one = 0;

    ll ans = 0;

    int tt = k/2 + 1;

    for (int i = n - 1; i >= 0; i--){
        int j = i % kk;
        int jj = (i + 1) % kk;

        int tot = min(kk, n - i);

        if (arr[i] != -1) {
            if (mp[j] != -1){
                if (mp[j] != arr[i]){
                    break;
                }
            } else {
                mp[j] = arr[i];
                if (arr[i] == 0){
                    zero++;
                } else {
                    one++;
                }
            }
        }

        int free = tot - zero - one;

        bool canZero = cnt[i].first == 0;
        bool canOne = cnt[i].second == 0;

        if (i == n - k + 1){
            if (canOne){
                int z = zero, o = one, f = free;
                z++;
                rep(l, 0, tt - o){
                    ans += choose(f, l, MOD);
                    ans %= MOD;
                }
            }

            if (canZero){
                int z = zero, o = one, f = free;
                o++;
                rep(l, 0, tt - z){
                    ans += choose(f, l, MOD);
                    ans %= MOD;
                }
            }
        }

        if (i == 0 || i > n - k){
            continue;
        }

        int t = kk/2;

        if (canZero && mp[j] != 1){
            // ..1.0
            int z = zero, o = one, f = free;
            if (mp[j] == -1){
                z++;
                f--;
            }

            if (z <= t && f >= t - z){
                ans += choose(f, t - z, MOD);
                ans %= MOD;
            }
        }

        if (canOne && mp[j] != 0){
            // ..0.1
            int z = zero, o = one, f = free;
            if (mp[j] == -1){
                o++;
                f--;
            }

            if (z <= t && f >= t - z){
                ans += choose(f, t - z, MOD);
                ans %= MOD;
            }
        }
    }

    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    factorial(MOD);
    factorial_inverses(MOD);

    int tc;
    cin >> tc;
    for (int t = 1; t <= tc; ++t){
        // cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}