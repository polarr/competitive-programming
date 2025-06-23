/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-06-22
 * Contest: Codeforces 2075
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

void solve(){
    ll n, m; cin >> n >> m;

    vl a(m);
    rep(i, 0, m){
        ll x; cin >> x;
        x = min(x, n - 1);
        a[i] = x;
    }

    sort(all(a));

    vl suff(m);
    suff[m - 1] = a[m - 1];
    for (int i = m - 2; i >= 0; i--){
        suff[i] = a[i] + suff[i + 1];
    }

    sort(all(a));
    ll ans = 0;
    rep(i, 0, m - 1){
        auto j = lower_bound(all(a), n - a[i]);
        if (j == a.end()) continue;
        ll idx = max((int)(j - a.begin()), i + 1);
        ll can = m - idx;
        ans += 2 * can * a[i] + 2 * suff[idx] - 2 * can * n + 2 * can;
    }
    cerr << endl;
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