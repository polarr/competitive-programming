/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-11-02
 * Contest: Codeforces 1140
 * Problem: G
**/

#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define pb push_back
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 5e17;

void solve(){
    int n; cin >> n;

    vl cross(n);
    rep(i, 0, n) cin >> cross[i];

    vector<vector<array<ll, 3>>> adj(n);
    rep(i, 0, n - 1){
        int a, b; cin >> a >> b;
        --a; --b;
        ll w1, w2; cin >> w1 >> w2;
        adj[a].pb({b, w1, w2});
        adj[b].pb({a, w1, w2});
    }

    int lg = log2(n) + 1;
    vi pow2(lg);
    rep(i, 0, lg){
        pow2[i] = (1 << i);
    }

    vl minCross = cross, upCross = cross;
    vi depth(n, 0);
    vector<vector<pii>> jp(n, vector<pii>(lg, {-1, 0}));
    using T = array<ll, 2>;
    vector<vector<array<T, 2>>> jmp(n, vector<array<T, 2>>(lg));
    function<void(int, int)> dfs1, dfs2;
    dfs1 = [&](int node, int par) {
        for (auto [x, w1, w2] : adj[node]){
            if (x == par) continue;
            depth[x] = depth[node] + 1;
            jp[x][0] = {node, 1};
            dfs1(x, node);
            minCross[node] = min(minCross[node], w1 + w2 + minCross[x]);
        }
    };

    dfs2 = [&](int node, int par) {
        upCross[node] = min(upCross[node], minCross[node]);

        ll mn = min(upCross[node], minCross[node]);

        for (auto [x, w1, w2] : adj[node]){
            if (x == par) continue;
            upCross[x] = min(upCross[x], w1 + w2 + upCross[node]);
            dfs2(x, node);

            jmp[x][0][0][0] = min(w1, minCross[x] + w2 + mn);
            jmp[x][0][0][1] = min(w1 + mn, minCross[x] + w2);
            jmp[x][0][1][0] = min(w2 + mn, minCross[x] + w1);
            jmp[x][0][1][1] = min(w2, minCross[x] + w1 + mn);
        }
    };

    dfs1(0, -1);
    dfs2(0, -1);
    rep(k, 1, lg){
        rep(i, 0, n){
            pii x = jp[i][k - 1];
            if (x.first == -1) continue;
            pii y = jp[x.first][k - 1];
            if (y.first == -1) continue;
            jp[i][k] = {y.first, y.second + x.second};
        }
    }

    rep(k, 1, lg){
        rep(i, 0, n){
            ll a = -1, b = -1, c = -1, d = -1;
            if (jp[i][k].first != -1){
                int j = jp[i][k - 1].first;
                a = min(jmp[i][k - 1][0][0] + jmp[j][k - 1][0][0], jmp[i][k - 1][0][1] + jmp[j][k - 1][1][0]);
                b = min(jmp[i][k - 1][0][0] + jmp[j][k - 1][0][1], jmp[i][k - 1][0][1] + jmp[j][k - 1][1][1]);
                c = min(jmp[i][k - 1][1][1] + jmp[j][k - 1][1][0], jmp[i][k - 1][1][0] + jmp[j][k - 1][0][0]);
                d = min(jmp[i][k - 1][1][1] + jmp[j][k - 1][1][1], jmp[i][k - 1][1][0] + jmp[j][k - 1][0][1]);
            }

            jmp[i][k][0][0] = a;
            jmp[i][k][0][1] = b;
            jmp[i][k][1][0] = c;
            jmp[i][k][1][1] = d;
        }
    }

    auto minDist = [&](int a, bool compA, int b, bool compB) -> ll {
        int d = depth[a] - depth[b];
        if (d == 0){
            if (compA == compB){
                return 0;
            }

            return min(upCross[a], minCross[a]);
        }

        int at = a;
        vector<pii> visit;
        rep(i, 0, lg){
            if (d & pow2[i]){
                visit.pb({at, i});
                at = jp[at][i].first;
            }
        }

        ll dp0 = INF, dp1 = INF;
        if (compB){
            dp1 = 0;
        } else {
            dp0 = 0;
        }

        for (int i = sz(visit) - 1; i >= 0; i--){
            auto [a, k] = visit[i];
            ll pdp0 = dp0;
            dp0 = min(jmp[a][k][0][1] + dp1, jmp[a][k][0][0] + dp0);
            dp1 = min(jmp[a][k][1][1] + dp1, jmp[a][k][1][0] + pdp0);
        }

        if (compA){
            return dp1;
        } else {
            return dp0;
        }
    };

    int q; cin >> q;
    rep(i, 0, q){
        int a, b; cin >> a >> b;
        --a; --b;
        bool compA = a % 2;
        bool compB = b % 2;
        a /= 2;
        b /= 2;

        if (depth[a] < depth[b]){
            swap(a, b);
            swap(compA, compB);
        }

        int d = depth[a] - depth[b];
        int ca = a, cb = b;
        rep(j, 0, lg){
            if (d & pow2[j]){
                ca = jp[ca][j].first;
            }
        }

        int lca;
        for (int j = lg - 1; j >= 0; j--){
            if (jp[ca][j].first != jp[cb][j].first){
                ca = jp[ca][j].first;
                cb = jp[cb][j].first;
            }
        }

        if (ca == cb){
            lca = ca;
        } else {
            lca = jp[ca][0].first;
        }

        ll ans = min(minDist(a, compA, lca, 0) + minDist(b, compB, lca, 0), minDist(a, compA, lca, 1) + minDist(b, compB, lca, 1));

        cout << ans << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}