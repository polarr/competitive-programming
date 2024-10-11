/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-10-10
 * Contest: CSES Problemset - Dynamic Programming
 * Problem: 1746
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

void solve(){
    int n, m; cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int j = 1; j < m + 1; j++){
        if (arr[0] == j || arr[0] == 0){
            dp[1][j] = 1;
        }
    }

    for (int i = 2; i < n + 1; i++){
        int x = arr[i - 1];
        for (int j = 1; j < m + 1; j++){
            if (x != 0 && j != x){
                dp[i][j] = 0;
                continue;
            }

            ull a = 0;
            for (int k = max(1, j - 1); k <= min(m, j + 1); k++){
                a += dp[i - 1][k];
                a %= MOD;
            }
            dp[i][j] = a;
        }
    }

    ull ans = 0;
    for (int j = 1; j < m + 1; j++){
        ans += dp[n][j];
        ans %= MOD;
    }

    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}