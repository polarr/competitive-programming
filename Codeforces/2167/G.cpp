/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-11-13
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

const ll INF = 1e17;

void solve(){
    int n; cin >> n;

    vl arr(n), cost(n);
    vector<pair<ll, int>> brr(n);
    rep(i, 0, n){
        ll x; cin >> x;
        arr[i] = x;
        brr[i] = {x, i};
    }

    rep(i, 0, n) cin >> cost[i];

    sort(all(brr));
    int cnt = 0;
    rep(i, 0, n){
        if (i != 0 && brr[i].first > brr[i - 1].first){
            cnt++;
        }

        arr[brr[i].second] = cnt;
    }

    vl dp(n, INF);

    rep(i, 0, n){
        if (arr[0] <= i){
            dp[i] = 0;
        } else {
            dp[i] = cost[0];
        }
    }

    rep(i, 1, n){
        vl ndp(n, INF);
        rep(j, 0, n){
            if (arr[i] <= j){
                ndp[j] = min(ndp[j], dp[arr[i]]);
            }

            ndp[j] = min(ndp[j], cost[i] + dp[j]);
        }

        dp = ndp;
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