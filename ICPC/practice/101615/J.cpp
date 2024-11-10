/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-11-09
 * Contest: ICPC Practice Codeforces 101615
 * Problem: J
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

void solve(){
    int m, n; cin >> m >> n;
 
    vector<vector<ll>> dp(m + 1, vector<ll>(n, 0));
    vector<vector<ll>> grid = dp;
    for (int i = 0; i < m; i++){
        string s; cin >> s;
        for (int j = 0; j < n; j++){
            char h = s[j];
            if (h == '.') continue;
            grid[i][j] = (h == 'B' ? 2: 1);
        }
    }
 
    vector<pair<int, int>> bound(n);
 
    for (int j = 0; j < n; j++){
        int maxB = 0;
        int minA = m + 1;
        for (int i = 0; i < m; i++){
            if (grid[i][j] == 2){
                maxB = max(maxB, i + 1);
            } else if (grid[i][j] == 1){
                minA = min(minA, i + 1);
            }
        }
        bound[j] = {maxB, minA};
    }
 
    for (int i = bound[0].first; i < bound[0].second; i++){
        dp[i][0] = 1;
    }
 
    for (int j = 1; j < n; j++){
        for (int i = bound[j].first; i < bound[j].second; i++){
            for (int k = i; k < m + 1; k++){
                dp[i][j] += dp[k][j - 1];
            }
        }
    }
 
    ll ans = 0;
    for (int i = 0; i < m + 1; i++){
        ans += dp[i][n - 1];
    }
 
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}