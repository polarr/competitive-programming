/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-10-08
 * Contest: CSES Problemset - Dynamic Programming
 * Problem: 1638 - Coin Combinations I
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

void solve(){
    int n; cin >> n;
    vector<vector<int>> grid(n + 1, vector<int> (n + 1, 1));
    vector<vector<ull>> dp(n + 1, vector<ull> (n + 1, 0));

    for (int i = 0; i < n; i++){
        string s; cin >> s;
        for (int j = 0; j < n; j++){
            if (s[j] == '.'){
                grid[i + 1][j + 1] = 0;
            }
        }
    }

    for (int i = 1; i < n + 1; i++){
        for (int j = 1; j < n + 1; j++){
            if (grid[i][j] == 1){
                dp[i][j] = 0;
                continue;
            }

            if (i == 1 && j == 1){
                dp[1][1] = 1;
                continue;
            }

            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
        }
    }

    cout << dp[n][n] % MOD << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}