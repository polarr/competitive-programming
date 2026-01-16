/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2026-01-15
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
    int a, b, m; cin >> a >> b >> m;

    int n = a + b;
    vector<pii> edges(m);
    vector<vector<pii>> adj(n);
    vi deg(n, 0);

    rep(i, 0, m) {
        int x, y; cin >> x >> y;
        x--; y--; y += a;

        adj[x].pb({y, i});
        adj[y].pb({x, i});
        edges[i] = {x, y};
        deg[x]++; deg[y]++;
    }

    int d = 0;
    rep(i, 0, n) {
        d = max(d, deg[i]);
    }

    vector<vi> taken(n, vi(d, -1));
    vi ans(m, -1);

    vector<bool> visited(n, false);
    function<void(int, int, int)> dfs;
    dfs = [&](int node, int x, int o) {
        if (visited[node]) {
            return;
        }

        visited[node] = true;
        int e = taken[node][o];
        int onode = edges[e].first;
        if (onode == node) {
            onode = edges[e].second;
        }

        if (taken[onode][x] >= 0) {
            dfs(onode, o, x);
        } else {
            taken[onode][o] = -1;
        }

        ans[e] = x;
        taken[node][x] = taken[onode][x] = e;
    };

    rep(i, 0, m) {
        auto [x, y] = edges[i];
        int a, b;
        bool good = false;
        rep(c, 0, d) {
            if (taken[y][c] >= 0 && taken[x][c] >= 0) continue;
            if (taken[y][c] < 0 && taken[x][c] < 0) {
                ans[i] = c;
                taken[y][c] = i;
                taken[x][c] = i;
                good = true;
                break;
            }

            if (taken[y][c] < 0) {
                a = c;
            }

            if (taken[x][c] < 0) {
                b = c;
            }
        }

        if (good) continue;
        // have a, b
        visited = vector<bool>(n, false);
        dfs(x, b, a);
        ans[i] = a;
        taken[x][a] = taken[y][a] = i;
    }

    cout << d << endl;
    rep(i, 0, m) {
        cout << ans[i] + 1 << " ";
    }
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}