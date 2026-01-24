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
    int n, m; cin >> n;

    vi to(n);
    vector<vi> from(n);
    rep(i, 0, n) {
        int x; cin >> x;
        --x;
        to[i] = x;
        if (x == i) continue;
        from[x].pb(i);
    }

    cin >> m;

    array<int, 3> curr;
    rep(i, 0, 3) curr[i] = 0;
    vi party(n, 3);

    vi order;
    vector<array<int, 3>> queries(m);
    rep(i, 0, m) {
        int c; cin >> c;
        --c;

        if (party[c] == 3) {
            order.pb(c);
        }

        char v; cin >> v;
        int t = 0;
        if (v == 'O') {
            t = 1;
        } else if (v == 'W') {
            t = 2;
        }

        queries[i] = {c, party[c], t};
        party[c] = t;
    }

    vector<array<int, 3>> ans(m);

    vi go(n, -1);
    vi cnt(n, 0);
    vector<bool> visited(n, false);
    function<void(int, int)> dfs;
    dfs = [&](int x, int o) {
        if (x != o) go[x] = o;
        if (x != o && party[x] != 3) return;
        if (visited[x]) return;
        visited[x] = true;
        cnt[o]++;
        for (int node : from[x]) {
            dfs(node, o);
        }
    };

    rep(j, 0, sz(order)) {
        int i = order[j];
        dfs(i, i);
        curr[party[i]] += cnt[i];
    }

    function<int(int, int)> find;
    find = [&](int p, int st) {
        if (p == -1 || party[p] != 3) {
            return p;
        }

        if (go[p] == st) {
            return -1;
        }

        return go[p] = find(go[p], st);
    };

    for (int i = m - 1; i >= 0; i--) {
        auto [x, pr, nw] = queries[i];
        ans[i] = curr;
        curr[nw] -= cnt[x];
        party[x] = pr;
        if (pr != 3) {
            curr[pr] += cnt[x];
        } else {
            int p = find(x, x);

            if (p != -1) {
                cnt[p] += cnt[x];
                curr[party[p]] += cnt[x];
            }
        }
    }

    rep(i, 0, m) {
        cout << ans[i][0] << " " << ans[i][1] << " " << ans[i][2] << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}