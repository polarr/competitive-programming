/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-09-21
 * Contest: Codeforces 2140
 * Problem: E2
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

void solve(){
    int n, m, k; cin >> n >> m >> k;
    vi good(n, false);

    rep(i, 0, k){
        int c; cin >> c;
        --c;
        good[c] = true;
    }

    bool dpa[n][1 << n], dpb[n][1 << n];
    dpa[0][1] = true, dpa[0][0] = false;
    dpb[0][0] = true, dpb[0][1] = false;

    rep(l, 1, n){
        rep(i, 0, 1 << (l + 1)){
            int curr = 0;
            dpa[l][i] = false;
            dpb[l][i] = false;
            rep(j, 0, l + 1){
                int pw = 1 << j;
                int nx = i - curr;
                if (i & pw){
                    nx -= pw;
                }

                nx /= 2;
                nx += curr;

                if (good[l - j]){
                    dpa[l][i] |= !dpb[l - 1][nx];
                    dpb[l][i] |= !dpa[l - 1][nx];
                }

                if (i & pw){
                    curr += pw;
                }
            }
        }
    }

    // ll precomp[n + 1][n + 1];

    // rep(i, 0, n + 1){
    //     rep(r, 0, n + 1){
    //         precomp[i][r] = 0;
    //         rep(k, 1, m + 1){
    //             precomp[i][r] += k * mod_exp(k - 1, n - r, MOD) % MOD * mod_exp(m - k, i, MOD) % MOD;
    //             precomp[i][r] %= MOD;
    //         }
    //     }
    // }

    // ll comp[1 << n][n + 1], sos[1 << n][n + 1][n + 1], ones[1 << n];
    // rep(i, 0, 1 << n){
    //     int one = 0;
    //     rep(j, 0, n){
    //         int pw = 1 << j;
    //         if (i & pw){
    //             one++;
    //         }
    //     }
    //     ones[i] = one;

    //     rep(r, 0, n + 1){

    //         sos[i][r][0] = 0;
    //         if (!dpa[n - 1][i]) sos[i][r][0] = precomp[one][r];
    //         rep(j, 0, n){
    //             sos[i][r][j + 1] = sos[i][r][j];
    //             int pw = 1 << j;
    //             if (i & pw){
    //                 sos[i][r][j + 1] += sos[i ^ pw][r][j];
    //                 sos[i][r][j + 1] %= MOD;
    //             }
    //         }

    //         comp[i][r] = sos[i][r][n];
    //     }
    // }

    // BRUH!!!!!!

    ll cnt[n + 1];
    rep(i, 0, n + 1) cnt[i] = 0;
    
    rep(i, 0, 1 << n){
        if (!dpa[n - 1][i]) continue;
        int ones = 0;
        rep(j, 0, n){
            if (i & (1 << j)){
                ones++;
            }
        }

        cnt[ones]++;
    }

    ll ans = 0;
    rep(k, 1, m + 1){
        rep(r, 0, n + 1){
            ans += mod_exp(k - 1, n - r, MOD) % MOD * mod_exp(m - k + 1, r, MOD) % MOD * cnt[r] % MOD;
            ans %= MOD;
        }
    }

    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for (int t = 1; t <= tc; ++t){
        // cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}