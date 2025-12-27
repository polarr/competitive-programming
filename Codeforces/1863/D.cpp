/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-12-26
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
    int n, m; cin >> n >> m;

    vector<vi> ver(n - 1);
    vector<vi> hor(m - 1);
    // vector<vi> grid(n, vi(m));
    rep(i, 0, n) {
        rep(j, 0, m) {
            char x; cin >> x;
            if (x == 'U') {
                ver[i].pb(j);
            }

            if (x == 'L') {
                hor[j].pb(i);
            }
        }
    }

    vector<vector<char>> ans(n, vector<char>(m, '.'));

    rep(i, 0, n - 1) {
        if (sz(ver[i]) % 2 == 1) {
            cout << -1 << endl;
            return;
        }

        for (int k = 0; k < sz(ver[i]); k += 2) {
            int j = ver[i][k];
            int jj = ver[i][k + 1];

            ans[i][j] = 'W';
            ans[i + 1][j] = 'B';
            ans[i][jj] = 'B';
            ans[i + 1][jj] = 'W';
        }
    }

    rep(j, 0, m - 1) {
        if (sz(hor[j]) % 2 == 1) {
            cout << -1 << endl;
            return;
        }

        for (int k = 0; k < sz(hor[j]); k += 2) {
            int i = hor[j][k];
            int ii = hor[j][k + 1];

            ans[i][j] = 'W';
            ans[i][j + 1] = 'B';
            ans[ii][j] = 'B';
            ans[ii][j + 1] = 'W';
        }
    }

    rep(i, 0, n) {
        rep(j, 0, m) {
            cout << ans[i][j];
        }
        cout << '\n';
    }
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