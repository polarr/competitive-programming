/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-12-07
 * Contest: 
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

const int MAX_N = 1e5 + 1;
const ll MOD = 998244353;

void solve(){
    int n, m, d; cin >> n >> m >> d;
    vector<vector<bool>> grid(n, vector<bool>(m, false));
    rep(i, 0, n) {
        rep(j, 0, m) {
            char t; cin >> t;
            if (t == 'X') {
                grid[i][j] = true;
            }
        }
    }

    vl dp1(m, 0), dp2(m, 0);
    rep(i, 0, m) {
        if (grid[0][i]) {
            dp1[i] = 1;
        }
    }  

    int lo = 0, hi = -1;
    ll curr = 0;
    rep(i, 0, m) {
        while (lo < i - d) {
            curr += MOD - dp1[lo];
            curr %= MOD;
            lo++;
        }

        while (hi < min(m - 1, i + d)) {
            hi++;
            curr += dp1[hi];
            curr %= MOD;
        }

        if (grid[0][i]) {
            dp2[i] = curr;
        }
    }

    rep(j, 1, n) {
        int lo = 0, hi = -1;
        ll curr = 0;
        rep(i, 0, m) {
            while (lo <= i - d) {
                curr += MOD - dp2[lo];
                curr %= MOD;
                lo++;
            }

            while (hi < min(m - 1, i + d - 1)) {
                hi++;
                curr += dp2[hi];
                curr %= MOD;
            }

            if (grid[j][i]) {
                dp1[i] = curr;
            } else {
                dp1[i] = 0;
            }
        }
        
        lo = 0, hi = -1;
        curr = 0;
        rep(i, 0, m) {
            while (lo < i - d) {
                curr += MOD - dp1[lo];
                curr %= MOD;
                lo++;
            }

            while (hi < min(m - 1, i + d)) {
                hi++;
                curr += dp1[hi];
                curr %= MOD;
            }

            if (grid[j][i]) {
                dp2[i] = curr;
            } else {
                dp2[i] = 0;
            }
        }
    }

    ll ans = 0;
    rep(i, 0, m) {
        ans += dp2[i];
        ans %= MOD;
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