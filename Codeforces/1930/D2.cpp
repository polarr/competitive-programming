/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-07-05
 * Contest: Codeforces 1930
 * Problem: D
**/

#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using pii = pair<int, int>;
#define pb push_back
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

void solve(){
    int n; cin >> n;
    string s; cin >> s;

    vl dp(n + 1, 0);
    int lastOne = -1, secondLastOne = -1;
    rep(i, 0, n){
        if (s[i] == '0'){
            dp[i + 1] = dp[i];
            continue;
        }

        int j = 0;
        if (lastOne == -1){
            j = 0;
        } else if (secondLastOne != -1 && i + 1 - secondLastOne <= 2){
            j = secondLastOne - 1;
        }
        else if (i + 1 - lastOne <= 2) {
            j = lastOne - 1;
        } else {
            j = i;
        }

        dp[i + 1] = dp[j] + (ll)i + 1;

        secondLastOne = lastOne;
        lastOne = (ll)i + 1;
    }

    ll sum = 0;
    rep(i, 0, n + 1){
        sum += dp[i];
    }

    cout << sum << endl;
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