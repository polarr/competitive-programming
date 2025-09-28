/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-09-27
 * Contest: VJudge 751735
 * Problem: H
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

    vi arr(n + 1, -1);
    rep(i, 0, n) cin >> arr[i + 1];

    vl dp(n + 1, 1), dp2(n + 1, 1), p(n + 1, 1);

    stack<pii> nse;
    nse.push({-1, 0});
    rep(i, 1, n + 1){
        while (arr[i] < nse.top().first){
            nse.pop();
        }

        int sm = nse.top().second;
        p[i] = p[i - 1];
        dp2[i] = p[i - 1] + MOD - p[sm];
        dp2[i] += dp[sm];
        dp2[i] %= MOD;
        p[i] += dp2[i];
        p[i] %= MOD;
        dp[i] = dp2[i];
        dp[i] += (sm == 0 ? 0 : dp[sm]);
        dp[i] %= MOD;

        nse.push({arr[i], i});
    }

    cout << dp[n] << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}