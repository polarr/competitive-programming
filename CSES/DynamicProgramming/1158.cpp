/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-10-15
 * Contest: CSES Problemset = Dynamic Programming
 * Problem: 1158
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

void solve(){
    int n, x; cin >> n >> x;
    vector<pair<int, int>> books(n, {0, 0});
    for (int i = 0; i < n; i++){
        int a; cin >> a;
        books[i].first = a;
    }

    for (int i = 0; i < n; i++){
        int a; cin >> a;
        books[i].second = a;
    }

    vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));

    for (int i = 1; i < n + 1; i++){
        for (int j = 1; j < x + 1; j++){
            dp[i][j] = dp[i - 1][j];
            if (books[i - 1].first <= j){
                dp[i][j] = max(dp[i][j], books[i - 1].second + dp[i - 1][j - books[i - 1].first]);
            }
        }
    }

    cout << dp[n][x] << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}