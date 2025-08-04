/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-08-02
 * Contest: CSES Problemset
 * Problem: 3403
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
    int n, m; cin >> n >> m;
    int a[n], b[m];
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, m) cin >> b[i];

    int dp[n + 1][m + 1];
    rep(i, 0, n + 1){
        dp[i][0] = 0;
    }

    rep(i, 0, m + 1){
        dp[0][i] = 0;
    }

    rep(i, 1, n + 1){
        rep(j, 1, m + 1){
            if (a[n - i] == b[m - j]){
                dp[i][j] = 1 + dp[i - 1][j - 1];
                continue;
            }

            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    
    cout << dp[n][m] << endl;

    int i = n, j = m;
    while (i > 0 && j > 0){
        if (a[n - i] == b[m - j]){
            cout << a[n - i] << " ";
            --i; --j;
            continue;
        }

        if (dp[i - 1][j] > dp[i][j - 1]){
            --i;
        } else {
            --j;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}