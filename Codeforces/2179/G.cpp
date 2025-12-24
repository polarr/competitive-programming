/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-12-23
 * Contest: 
 * Problem: G
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

int ask(int i, int j) {
    cout << "? " << i + 1 << " " << j + 1 << endl;
    int d; cin >> d;
    return d;
}

void solve(){
    int n; cin >> n;

    int sq = n * n;
    int mx = 0;
    int corner = 0;

    rep(i, 1, sq) {
        int d = ask(0, i);
        if (d > mx) {
            mx = d;
            corner = i;
        }
    }

    vector<pii> dist(sq);
    vector<vi> dist1(2 * n - 1);
    rep(i, 0, sq) {
        int d = ask(corner, i);
        dist[i].first = d;
        dist1[d].pb(i);
    }

    int a = dist1[n - 1][0];
    mx = 0;
    int b = 0;

    rep(i, 1, n) {
        int d = ask(a, dist1[n - 1][i]);
        if (d > mx) {
            mx = d;
            b = dist1[n - 1][i];
        }
    }

    rep(i, 0, sq) {
        int d = ask(b, i);
        dist[i].second = d;
    }

    vector<vi> grid(n, vi(n));

    rep(i, 0, sq) {
        int y = dist[i].first + dist[i].second - (n - 1);
        y /= 2;
        int x = dist[i].first - y;
        grid[x][y] = i;
    }

    cout << "!" << endl;
    rep(i, 0, n) {
        rep(j, 0, n) {
            cout << grid[i][j] + 1 << " ";
        }
        cout << endl;
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