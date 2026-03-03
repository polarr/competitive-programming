/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2026-03-02
 * Contest: 
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
    int n, x, y; cin >> n >> x >> y;

    vi a, b;
    rep(i, 0, x) {
        int d; cin >> d;
        a.pb(d);
    }

    rep(i, x, y) {
        int d; cin >> d;
        b.pb(d);
    }

    rep(i, y, n) {
        int d; cin >> d;
        a.pb(d);
    }

    vi ans;

    auto j = min_element(all(b));
    int m = *j;
    rotate(b.begin(), j, b.end());

    int i = 0;
    while (i < sz(a) && a[i] < m) {
        ans.pb(a[i]);
        i++;
    } 

    rep(i, 0, sz(b)) {
        ans.pb(b[i]);
    }

    while (i < sz(a)) {
        ans.pb(a[i]);
        i++;
    }

    rep(i, 0, n) {
        cout << ans[i] << " ";
    }

    cout << endl;
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