/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-03-07
 * Contest: CSES Problemset
 * Problem: 1140
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
    vector<array<ll, 3>> p(n);
    rep(i, 0, n){
        ll a, b, c; cin >> a >> b >> c;
        p[i] = {a, b, c};
    }

    sort(p.begin(), p.end());
    vl dp(n + 1, 0);
    for (int i = n - 1; i >= 0; i--){
        ll a = dp[i + 1];
        int nx = upper_bound(all(p), array<ll, 3>{p[i][1], INT_MAX, INT_MAX}) - p.begin();
        ll b = p[i][2] + dp[nx];

        dp[i] = max(a, b);
    }

    cout << dp[0] << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}