/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-10-18
 * Contest: 
 * Problem: C
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

const int MAX_N = 4e5 + 1;
const ll MOD = 1e9 + 7;


void solve(){
    ll n; cin >> n;

    vl dp(n + 2, 1);
    rep(i, 2, n + 2){
        dp[i] = 2 * dp[i - 1] + (ll)(i - 2) * dp[i - 2];
        dp[i] %= MOD;
    }

    vl a(n + 1);
    rep(i, 0, n + 1) cin >> a[i];

    vector<bool> visited(n + 1, false);
    int can = 0;
    rep(i, 0, n + 1){
        if (visited[i]) continue;
        if (a[i] == -1) continue;
        if (a[i] == 0) {
            visited[i] = true;
            continue;
        }
        if (a[i] > n){
            cout << 0 << endl;
            return;
        }

        ll b = a[i];
        if (visited[b]){
            cout << 0 << endl;
            return;
        }

        visited[i] = true;
        visited[b] = true;

        if (a[b] == -1){
            a[b] = i;
        } else if (a[b] != i){
            cout << 0 << endl;
            return;
        }
    }

    rep(i, 0, n + 1){
        if (!visited[i]) {
            can++;
        }
    }

    ll ans = dp[can];
    if (!visited[0] && !visited[n]){
        ans += MOD - dp[can - 1];
    }

    ans %= MOD;

    cout << ans << endl;
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