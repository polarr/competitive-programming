/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-03-07
 * Contest: CSES Problemset
 * Problem: 1744
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
    int a, b; cin >> a >> b;
    vector<vi> dp(a + 1, vi(b + 1, 0));

    rep(i, 1, a + 1){
        rep(j, 1, b + 1){
            if (i == j) {
                continue;
            }

            int mx = min(i, j);
            int mn = INT_MAX;
            rep(k, 1, mx + 1){
                if (k == mx){
                    mn = min(mn, 1 + dp[i - k][j - k] + dp[i - k][k] + dp[k][j - k]);
                    continue;
                }

                mn = min(mn, 2 + dp[i - k][k] + dp[i][j - k]);
                mn = min(mn, 2 + dp[k][j - k] + dp[i - k][j]);
            }

            dp[i][j] = mn;
        }
    }

    cout << dp[a][b] << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}