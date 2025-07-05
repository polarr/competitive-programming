/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-07-05
 * Contest: 
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

void solve(){
    int n; ll m; cin >> n >> m;

    vl dp(n + 1, 0);
    dp[0] = 1;

    for (ll i = n - 1; i >= 0; i--){
        vl ndp(n + 1, 0);
        ll rem = (n - i);
        rep(j, 0, rem + 1){
            ndp[j] = dp[j];
            if (j != 0){
                ndp[j] += (i + 1LL) * (rem - (ll)j + 1LL) % m * dp[j - 1] % m;
                ndp[j] %= m;
            }
        }

        dp = ndp;
    }

    ll ans = 0;
    rep(i, 0, n + 1){
        ans += dp[i];
        ans %= m;
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