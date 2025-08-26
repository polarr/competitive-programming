/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-08-25
 * Contest: Codeforces 2133
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
    int n; cin >> n;
    vl h(n);
    rep(i, 0, n) cin >> h[i];

    vl dp(n);
    dp[0] = h[0];
    dp[1] = h[0] + max(0LL, h[1] - 1);
    rep(i, 2, n){
        dp[i] = min(dp[i - 1] + max(0LL, h[i] - 1), dp[i - 2] + h[i - 1] + max(0LL, h[i] - i));
    }

    cout << dp[n - 1] << endl;
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