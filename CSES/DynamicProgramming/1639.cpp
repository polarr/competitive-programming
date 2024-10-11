/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-10-10
 * Contest: CSES Problemset - Dynamic Programming
 * Problem: 1639
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

void solve(){
    string a, b; cin >> a >> b;

    if (a.length() > b.length()){
        swap(a, b);
    }

    int n = a.length(), m = b.length();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i < m + 1; i++){
        dp[i][0] = i;
    }

    for (int j = 1; j < n + 1; j++){
        dp[0][j] = j;
    }

    for (int i = 1; i < m + 1; i++){
        for (int j = 1; j < n + 1; j++){
            if (b[i - 1] == a[j - 1]){
                dp[i][j] = dp[i - 1][j - 1];
                continue;
            }

            dp[i][j] = 1 + min(dp[i][j - 1], min(dp[i - 1][j - 1], dp[i - 1][j]));
        }
    }

    cout << dp[m][n] << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}