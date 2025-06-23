/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-06-23
 * Contest: 
 * Problem: E
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

const int MAX_N = 5e5 + 1;
const ll MOD = 1e9 + 7;

vi dp(MAX_N, MAX_N);

void solve(){
    int m; cin >> m;

    cout << (dp[m] == MAX_N ? -1 : dp[m]) << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    dp[1] = 1;

    rep(i, 2, MAX_N){
        int rt = sqrt(i);

        dp[i] = min(dp[i], dp[i - 2] + 1);

        rep(j, 2, rt + 1){
            if (i % j != 0) continue;
            dp[i] = min(dp[i], dp[j] + dp[i/j] - 1);
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