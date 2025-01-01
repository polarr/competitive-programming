/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-12-27
 * Contest: CSES Problemset
 * Problem: 1637
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

void solve(){
    vector<int> dp(1e6 + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i < 1e6 + 1; i++){
        vector<int> digits;
        int k = i;
        while (k != 0){
            if (k % 10 != 0){
                digits.pb(k % 10);
            }
            k /= 10;
        }

        for (int j = 0; j < digits.size(); j++){
            dp[i] = min(dp[i], 1 + dp[i - digits[j]]);
        }
    }

    int n; cin >> n;
    cout << dp[n] << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}