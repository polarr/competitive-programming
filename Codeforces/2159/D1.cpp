/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-10-19
 * Contest: 
 * Problem: D1
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
    vl arr(n);
    rep(i, 0, n) cin >> arr[i];

    vl mn(n + 1, LLONG_MAX);
    vl small(n + 1, n);
    for (int i = n - 1; i >= 0; i--){
        small[i] = small[i + 1];
        if (arr[i] < mn[i + 1]){
            small[i] = i;
        }

        mn[i] = min(arr[i], mn[i + 1]);
    }

    vl dp(n + 1, 0);

    for (int i = n - 1; i >= 0; i--){
        int sm = small[i];
        
        dp[i] = 1 + dp[sm + 1];

        int lo = sm + 1;
        int hi = n;
        while (lo < hi){
            int mid = (lo + hi)/2;
            if (mn[mid] > 2LL * arr[sm]){
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }

        dp[i] = min(dp[i], 2 + dp[lo]);

        lo = sm + 1, hi = n;
        while (lo < hi){
            int mid = (lo + hi)/2;
            if (mn[mid] > 3LL * arr[sm]){
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }

        dp[i] = min(dp[i], 3 + dp[lo]);
    }

    cout << dp[0] << endl;
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