/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-09-21
 * Contest: Codeforces 2140
 * Problem: E1
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

void solve(){
    int n, m, k; cin >> n >> m >> k;
    vi good(n, false);
    rep(i, 0, k){
        int c; cin >> c;
        --c;
        good[c] = true;
    }

    if (m == 1){
        cout << 1 << endl;
        return;
    }

    bool dpa[n][1 << n], dpb[n][1 << n];
    dpa[0][1] = true, dpa[0][0] = false;
    dpb[0][0] = true, dpb[0][1] = false;

    ll ans = n == 1 ? 3 : 0;

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

            if (l != n - 1) continue;

            if (dpa[l][i]){
                ans += 2;
            } else {
                ans += 1;
            }

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