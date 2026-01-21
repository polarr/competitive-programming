/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2026-01-20
 * Contest: 
 * Problem: E
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
    vi p(n);
    rep(i, 0, n) cin >> p[i];

    vector<vi> diff(n);
    rep(i, 0, n - 1) {
        int d = abs(p[i + 1] - p[i]);

        diff[d].pb(i);
    }

    set<int> splits;
    splits.insert(0);
    splits.insert(n - 1);

    auto cnt = [&](ll k) -> ll {
        return (k * (k + 1))/2;
    };

    ll ans = cnt(n - 1);

    rep(i, 1, n) {
        for (int j : diff[i - 1]) {
            auto nx = splits.upper_bound(j);
            auto pr = prev(nx);

            int a = *nx;
            int b = *pr;

            int len = a - b;
            ans -= cnt(len);
            ans += cnt(j - b);
            ans += cnt(a - j - 1);

            splits.insert(j);
            splits.insert(j + 1);
        }

        cout << ans << ' ';
    }

    cout << '\n';
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