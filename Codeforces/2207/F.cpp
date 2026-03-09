/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2026-03-08
 * Contest: 
 * Problem: F
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
    int n, m; cin >> n >> m;

    vector<vi> table(m, vi(n));

    vector<pii> ord(n * m);
    rep(i, 0, n * m) {
        cin >> ord[i].first;
    }
    rep(i, 0, n * m) {
        cin >> ord[i].second;
    }

    if (m >= n) {
        cout << n - 1 << endl;
        return;
    }

    rep(i, 0, n * m) {
        auto [x, y] = ord[i];
        --x; --y;
        table[y][x] = i;
    }

    // rep(i, 0, m) {
    //     rep(j, 0, n) {
    //         cout << table[i][j] << " ";
    //     }

    //     cout << endl;
    // }

    vi low(m, 1e9);
    vector<bool> good(n, true);
    for (int i = n - 1; i >= 0; i--) {
        rep(j, 0, m) {
            bool le = (table[j][i] < low[j]);
            if (!le) good[i] = false;
            low[j] = min(low[j], table[j][i]);
        }
    }

    int ans = 0;
    int curr = 0;
    rep(i, 0, n) {
        if (good[i]) {
            curr++;
        } else {
            ans++;
            ans += min(m, curr);
            curr = 0;
        }
    }

    if (curr > 0) {
        ans += min(m, curr);
    }

    cout << ans - 1 << endl;
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