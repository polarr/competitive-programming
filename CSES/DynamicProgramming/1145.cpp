/**
 * Solution by 1egend (polarity.sh)
 * Date: 2025-02-06
 * Contest: CSES Problemset
 * Problem: 1145
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
    vi arr(n);
    rep(i, 0, n){
        cin >> arr[i];
    }

    vi dp(n + 1, INT_MAX);
    dp[0] = -INT_MAX;
    rep(i, 0, n){
        auto idx = lower_bound(dp.begin(), dp.end(), arr[i]);
        if (idx != dp.end()){
            dp[idx - dp.begin()] = arr[i];
        }
    }

    for (int i = n; i >= 0; i--){
        if (dp[i] != INT_MAX){
            cout << i << endl;
            return;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}