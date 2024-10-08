/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-10-08
 * Contest: Leetcode Problemset
 * Problem: 1143 - Longest Common Subsequence
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

void solve(){
    string text1, text2; cin >> text1 >> text2;
    int n = text1.length(), m = text2.length();

    vector<int> t1(n);
    vector<int> t2(m);

    // nvm don't need the log n factor, can just push the calculation to i - 1, j unless last two elements are equal, in which case 1 + dp[i - 1, j - 1]

    // but it passes anyways
    vector<set<int>> last1(26);
    vector<set<int>> last2(26);

    for (int i = 0; i < n; i++){
        t1[i] = text1[i] - 'a';
        last1[t1[i]].insert(i + 1);
    }
    for (int i = 0; i < m; i++){
        t2[i] = text2[i] - 'a';
        last2[t2[i]].insert(i + 1);
    }

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i < n + 1; i++){
        for (int j = 1; j < m + 1; j++){
            int s = t2[j - 1];
            auto x = last1[s].upper_bound(i);
            if (x == last1[s].begin()){
                dp[i][j] = dp[i][j - 1];
                continue;
            }

            dp[i][j] = max(dp[i][j - 1], 1 + dp[*prev(x) - 1][j - 1]);
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