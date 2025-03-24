/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-03-21
 * Contest: DMOJ ahscc2
 * Problem: 6
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

    vi cnt(n, 0);

    rep(i, 0, n){
        string s; cin >> s;
        rep(j, 0, m){
            if (s[j] == '1'){
                cnt[i]++;
            }
        }
    }

    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));

    rep(i, 0, n + 1){
        dp[i][0] = true;
    }

    rep(i, 1, n + 1){
        int x = cnt[i - 1];
        dp[i][x] = true;
        rep(y, 0, m + 1){
            if (!dp[i - 1][y]) continue;
            int mx = x + y;
            if (mx > m){
                mx = m - (x + y) % m;
            } 
            for (int j = abs(x - y); j <= mx; j += 2){
                dp[i][j] = true;
            }
        }
    }

    for (int i = m; i >= 0; i--){
        if (dp[n][i]){
            rep(j, 0, i){
                cout << "1";
            }

            rep(j, 0, m - i){
                cout << "0";
            }
            
            cout << endl;
            return;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}