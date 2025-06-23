/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-06-22
 * Contest: Codeforces 2075
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

const int lg = 58;

ll dp[lg][lg][lg];

void solve(){
    ll x, y; cin >> x >> y;

    vl a, b;
    while (x > 0){
        a.pb(x % 2LL);
        x /= 2LL;
    }

    while (y > 0){
        b.pb(y % 2LL);
        y /= 2LL;
    }

    reverse(all(a));
    reverse(all(b));

    ll ans = dp[a.size()][b.size()][lg - 1];
    rep(i, 0, min(a.size(), b.size())){
        if (a[i] != b[i]) break;
        ans = min(ans, dp[a.size() - i - 1][b.size() - i - 1][lg - 1]);
    }

    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    rep(a, 0, lg){
        rep(b, 0, lg){
            rep(c, 0, lg){
                ll add = (1LL << (ll)(c));
                dp[a][b][c] = 1e18;
                if (c == 0){
                    if (a == 0 && b == 0){
                        dp[a][b][c] = 0;
                    }
                    continue;
                }
                
                dp[a][b][c] = min(dp[a][b][c], dp[a][b][c - 1]);

                dp[a][b][c] = min(dp[a][b][c], add + dp[max(0, a - c)][b][c - 1]);

                dp[a][b][c] = min(dp[a][b][c], add + dp[a][max(0, b - c)][c - 1]);
            }
        }
    }

    int tc;
    cin >> tc;
    for (int t = 1; t <= tc; ++t){
        // cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}