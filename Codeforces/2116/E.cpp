/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-06-18
 * Contest: Codeforces 2116
 * Problem: E
**/

#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
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

// bruh this so simple how 2700
void solve(){
    int n, m, pp; cin >> n >> m >> pp;
    double p = pp * 1.0/100;
    double q = 1.0 - p;

    vi h(n);
    rep(i, 0, n) cin >> h[i];

    if (n == 1){
        if (m >= h[0]){
            cout << 1.0 << endl;
        } else {
            cout << 0.0 << endl;
        }

        return;
    }

    sort(all(h));
    int extra = 0;
    rep(i, 1, n){
        extra += h[i] - h[0];
    }

    double dp[n * h[0] + 1][m + 1];
    rep(i, 0, n * h[0] + 1){
        dp[i][0] = 0;
    }
    dp[n][0] = 1;

    rep(i, 1, m + 1){
        rep(j, 0, n * h[0] + 1){
            if (j < n){
                dp[j][i] = 0;
                continue;
            }
            dp[j][i] = p * max(dp[j][i - 1], dp[j - n][i - 1]) + q * max(dp[j][i - 1], dp[j - 1][i - 1]);
        }
    }

    double ans = 0;
    double prob = 1;
    rep(i, 0, extra - 1){
        prob *= q;
    }
    if (extra == 0){
        ans = dp[n * h[0]][m];
    } else {
        rep(i, extra, m + 1){
            int shines = min(h[0] - 1, i - extra);

            ans += prob * q * dp[n * (h[0] - shines)][m - i];
            prob *= i;
            prob /= i - extra + 1;
            prob *= p;
        }
    }

    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    cout << fixed << setprecision(10);
    for (int t = 1; t <= tc; ++t){
        // cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}