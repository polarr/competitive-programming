/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-10-16
 * Contest: CSES Problemset - Dynamic Programming
 * Problem: 1665
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

/**
 * My original attempt, DP on first i (n) people, then DP on how many teams there are in cumulation with skill level cap t and scenario penalty x
void solve(){
    int n, x; cin >> n >> x;

    vector<int> skill(n + 1, -1);
    for (int i = 0; i < n; i++){
        cin >> skill[i + 1];
    }

    sort(skill.begin(), skill.end());

    vector<pair<vector<vector<int>>, vector<int>>> dp(n + 1, {vector<vector<int>>(101, vector<int>(x + 1, 0)), vector<int>(x + 1, 0)});

    dp[1].first[skill[1]][x]++;
    dp[1].second[x]++;

    for (int i = 2; i < n + 1; i++){
        int k = skill[i];

        dp[i].second = dp[i - 1].second;

        for (int r = 0; r < 101; r++){
            for (int s = 0; s < x + 1; s++){
                dp[i].first[r][s] = 2 * dp[i - 1].first[r][s];
                dp[i].first[r][s] %= MOD;
            }
        }

        for (int j = 0; j < x + 1; j++){
            int p = dp[i].second[j];
            dp[i].first[k][j] += p;
            dp[i].first[k][j] %= MOD;
        }

        for (int r = 0; r < 101; r++){
            for (int s = 0; s < x + 1; s++){
                if (k > r + s){
                    continue;
                }

                dp[i].first[r][s] = (dp[i].first[r][s] - 1 + MOD) % MOD;
                dp[i].first[k][s + r - k]++;
                dp[i].first[k][s + r - k] %= MOD;

                dp[i].second[s + r - k]++;
                dp[i].second[s + r - k] %= MOD;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < x + 1; i++){
        ans += dp[n].second[i];
        ans %= MOD;
    }

    cout << ans << endl;
}
*/

void solve(){
    /** NOTE: unsolved */

    int n, x; cin >> n >> x;

    vector<int> skill(n + 1, -1);
    for (int i = 0; i < n; i++){
        cin >> skill[i + 1];
    }

    sort(skill.begin(), skill.end());

    vector<vector<vector<ll>>> dp(2, vector<vector<ll>>(n + 1, vector<ll>(5000 + x + 1, 0)));

    dp[0][0][5000] = 1;

    for (int i = 1; i < 4; i++){
        int s = skill[i];
        for (int j = 0; j < n + 1 - i; j++){
            for (int k = 0; k < 5000 + x + 1; k++){
                dp[1][j][k] = ((ll)(j + 1) * dp[0][j][k] % MOD);

                if (j > 0 && k + s <= 5000 + x){
                    dp[1][j][k] += dp[0][j - 1][k + s];
                    dp[1][j][k] %= MOD;
                }

                if (j < n && k - s >= 0){
                    dp[1][j][k] += dp[0][j + 1][k - s];
                    dp[1][j][k] %= MOD;
                }
            }
        }

        dp[0] = dp[1];
    }

    int ans = 0;
    for (int k = 0; k < 5000 + x + 1; k++){
        ans += dp[0][1][k];
        if (dp[0][1][k] != 0){
            cout << k << " " <<dp[0][1][k] << endl;
        }
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