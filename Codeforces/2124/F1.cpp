/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-07-06
 * Contest: 
 * Problem: F1
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
const ll MOD = 998244353;

void solve(){
    int n, m; cin >> n >> m;

    vector<pii> rqs;
    rep(i, 0, m){
        int a, b; cin >> a >> b;
        rqs.pb({a, b});
    }

    sort(all(rqs));

    vl dp(n + 1, 0);
    dp[0] = 1;
    vector<vector<bool>> wasValid(n + 1, vector<bool>(n + 1, false));
    vector<bool> done(n, false);
    rep(i, 1, n + 1){
        rep(s, 1, i + 1){
            vi cannot;
            rep(j, 0, m){
                if (rqs[j].first <= i - s) continue;
                if (rqs[j].second > s) continue;
                if (rqs[j].first > i) break;

                int adj = rqs[j].first - (i - s);
                int invalid = (adj + s - rqs[j].second) % s;
                if (done[invalid]) continue;
                done[invalid] = true;
                cannot.pb(invalid);
            }

            if (!done[0]){
                wasValid[i][s] = true;
            }

            rep(j, 1, s){
                int invalid = j;
                if (done[invalid]) continue;

                int front = s + 1 - j;
                if (!wasValid[i - s][front - 1]) continue;

                dp[i] += MOD - (ll)(s - cannot.size()) * dp[i - s - front + 1] % MOD;
            }

            dp[i] += (ll)(s - cannot.size()) * dp[i - s] % MOD;
            dp[i] %= MOD;

            for (int cant : cannot){
                done[cant] = false;
            }
        }

        cerr << dp[i] << " ";
    }

    cerr << endl;

    cout << dp[n] << endl;
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