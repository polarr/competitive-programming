/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-10-10
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
const ll INF = 1e15;

void solve(){
    int n; cin >> n;
    vl arr(n);
    rep(i, 0, n) cin >> arr[i];
    
    auto calc = [&](vl& arr) -> ll {
        vl dp(n + 1, INF);
        dp[n] = 0;
        dp[n - 1] = INF;
        for (int i = n - 2; i >= 0; i--){
            ll cost = abs(arr[i] - arr[i + 1]);
            dp[i] = min(dp[i], dp[i + 2] + cost);
            if (i < n - 2){
                cost = max({arr[i], arr[i + 1], arr[i + 2]}) - min({arr[i], arr[i + 1], arr[i + 2]});
                dp[i] = min(dp[i], dp[i + 3] + cost);
            }
        }

        return dp[0];
    };

    ll ans = INF;
    ans = min(ans, calc(arr));
    rotate(arr.rbegin(), arr.rbegin() + 1, arr.rend());
    ans = min(ans, calc(arr));
    rotate(arr.rbegin(), arr.rbegin() + 1, arr.rend());
    ans = min(ans, calc(arr));

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