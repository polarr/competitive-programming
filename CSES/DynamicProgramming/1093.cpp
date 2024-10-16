/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-10-15
 * Contest: CSES Problemset - Dynamic Programming
 * Problem: 1093
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
    int mx = n * (n + 1)/2 + 1;
    vector<vector<int>> dp(n + 1, vector<int>(mx, 0));

    dp[0][0] = 1;

    for (int i = 1; i < n + 1; i++){
        for (int j = 0; j < mx; j++){
            int d = 0;
            if (j + i < i * (i - 1)/2 + 1){
                d += dp[i - 1][j + i];
                d %= MOD;
            }
            if (abs(j - i) < i * (i - 1)/2 + 1 && abs(j - i) >= 0){
                d += dp[i - 1][abs(j - i)];
                d %= MOD;
            }
            dp[i][j] = d;
        }
    }

    cout << (dp[n][0] % 2 == 0 ? dp[n][0]/2 : (dp[n][0] + MOD)/2) << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}