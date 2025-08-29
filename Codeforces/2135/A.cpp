/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-08-28
 * Contest: Codeforces 2135
 * Problem: A
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
    vi arr(n);
    rep(i, 0, n) cin >> arr[i];

    vector<vi> nums(n + 1);
    vi dp(n + 1, 0);
    rep(i, 0, n){
        dp[i + 1] = dp[i];
        int a = arr[i];
        nums[a].pb(i);
        if (nums[a].size() >= a){
            dp[i + 1] = max(dp[i + 1], a + dp[nums[a][nums[a].size() - a]]);
        }
    }

    cout << dp[n] << endl;
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