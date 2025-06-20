/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-06-18
 * Contest: 
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

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

void solve(){
    int n; cin >> n;
    vl a(n);
    rep(i, 0, n) cin >> a[i];

    ll dp[n + 1][n + 1];

    rep(i, 0, n){
        dp[i][i] = 0;
        dp[i][(i + 1) % n] = 0;
        dp[i][(i + n - 1) % n] = 0;
    }

    rep(d, 2, n){
        rep(i, 0, n){
            int j = (i + d) % n;
            dp[i][j] = dp[(i + 1) % n][j];
            dp[i][j] = max(dp[i][j], dp[i][(j + n - 1) % n]);
            rep(r, 1, d){
                int k = (i + r) % n;
                ll nx = a[i] * a[j] * a[k] + dp[(i + 1) % n][(k + n - 1) % n] + dp[(k + 1) % n][(j + n - 1) % n];
                dp[i][j] = max(dp[i][j], nx);
                dp[i][j] = max(dp[i][j], dp[i][k] + dp[(k + 1) % n][j]);
            }
        }
    }

    cout << dp[0][n - 1] << endl;
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