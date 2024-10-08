/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-10-05
 * Contest: ICPC NAQ 2024
 * Problem: K
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

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    vector<int> e(n);
    vector<int> a(m);

    for (int i = 0; i < n; i++){
        int x; cin >> x;
        e[i] = x;
    }

    for (int i = 0; i < m; i++){
        int x; cin >> x;
        a[i] = x;
    }

    auto calc = [&](int x, int y){
        int diff = abs(e[x] - a[y]);

        if (diff <= 15){
            return 7;
        }

        if (diff <= 23){
            return 6;
        }

        if (diff <= 43){
            return 4;
        }

        if (diff <= 102){
            return 2;
        }

        return 0;
    };

    for (int i = 1; i < n + 1; i++){
        for (int j = 1; j < m + 1; j++){
            dp[i][j] = max(calc(n - i, m - j) + dp[i - 1][j - 1], max(dp[i][j - 1], dp[i - 1][j]));
        }
    }

    cout << dp[n][m] << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}