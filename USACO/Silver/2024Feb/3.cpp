/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-02-19
 * Contest: USACO 2024 February Contest
 * Problem: P3. Moorbles
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

void solve(){
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> marbles(m);
    vector<int> dp(m + 1);
    for (int i = 0; i < m; i++){
        for (int j = 0; j < k; j++){
            int a;
            cin >> a;
            marbles[i].pb(a);
        }
    }

    dp[m] = 0;
    for (int i = m - 1; i >= 0; i--){
        vector<int> turn = marbles[i];

        int evenMax = 0;
        int oddMax = 0;
        int evenMin = INT_MAX;
        int oddMin = INT_MAX;
        for (int j = 0; j < k; j++){
            if (turn[j] % 2 == 0){
                evenMax = max(evenMax, turn[j]);
                evenMin = min(evenMin, turn[j]);
            } else {
                oddMax = max(oddMax, turn[j]);
                oddMin = min(oddMin, turn[j]);
            }
        }

        int add = min(oddMax, evenMax);

        if (evenMax == 0){
            add = -oddMin;
        }

        if (oddMax == 0){
            add = -evenMin;
        }

        dp[i] = max(add, dp[i + 1] + add);
    }

    if (dp[0] >= n){
        cout << -1 << endl;
        return;
    }

    int curr = n;

    for (int i = 0; i < m; i++){
        vector<int> turn = marbles[i];
        
        int evenMax = 0;
        int oddMax = 0;
        int evenMin = INT_MAX;
        int oddMin = INT_MAX;
        for (int j = 0; j < k; j++){
            if (turn[j] % 2 == 0){
                evenMax = max(evenMax, turn[j]);
                evenMin = min(evenMin, turn[j]);
            } else {
                oddMax = max(oddMax, turn[j]);
                oddMin = min(oddMin, turn[j]);
            }
        }

        if (oddMax == 0){
            cout << (i == m - 1 ? "Even":"Even ");
            curr += evenMin;
            continue;
        }

        if (evenMax >= oddMax){
            cout << (i == m - 1 ? "Even":"Even ");
            curr -= oddMax;
            continue;
        }

        if (curr - oddMax > max(0, dp[i + 1])){
            cout << (i == m - 1 ? "Even":"Even ");
            curr -= oddMax;
        } else {
            cout << (i == m - 1 ? "Odd":"Odd ");
            if (evenMax == 0){
                curr += oddMin;
            } else {
                curr -= evenMax;
            }
        }
    }

    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for (int t = 1; t <= tc; ++t){
        // cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}