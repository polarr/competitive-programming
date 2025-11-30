/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-11-29
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

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;

void solve(){
    int n, k; cin >> n >> k;
    vl arr(n), brr(n);
    rep(i, 0, n) cin >> arr[i];
    rep(i, 0, n) cin >> brr[i];

    vl sum(n + 1, 0);
    rep(i, 1, n + 1) {
        sum[i] = sum[i - 1] + arr[i - 1];
    }

    vl pre(n + 1, 0);
    vl suf(n + 1, -INF);
    rep(i, 1, n + 1) {
        pre[i] = min(pre[i - 1], sum[i]);
    }
    for (int i = n - 1; i >= 0; i--) {
        suf[i] = max(suf[i + 1], sum[i + 1]);
    }

    ll ans = -INF;
    rep(i, 0, n) {
        ll c = (k % 2 == 0 ? 0 : brr[i]);
        c += suf[i] - pre[i];

        ans = max(ans, c);
    }

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