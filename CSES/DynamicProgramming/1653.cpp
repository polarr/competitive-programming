/**
 * Solution by 1egend (polarity.sh)
 * Date: 2025-02-08
 * Contest: CSES Problemset
 * Problem: 1653
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
    int n, x; cin >> n >> x;
    vector<pii> dp(1 << n);
    vi weights(n);
    rep(i, 0, n){
        cin >> weights[i];
    }

    dp[0] = {1, 0};

    rep(i, 1, 1 << n){
        int mn = INT_MAX;
        int w = 1e9 + 1;
        rep(j, 0, n){
            if ((i & (1 << j)) == 0){
                continue;
            }

            pii prev = dp[i ^ (1 << j)];

            prev.second += weights[j];

            if (prev.second > x){
                prev.first++;
                prev.second = weights[j];
            }

            if (prev.first <= mn){
                w = min(w, prev.second);
            }

            mn = min(mn, prev.first);
        }

        dp[i] = {mn, w};
    }

    cout << dp[(1 << n) - 1].first << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}