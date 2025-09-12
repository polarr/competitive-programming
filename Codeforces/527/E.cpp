/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-09-11
 * Contest: Codeforces 527
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
    int n, m; cin >> n >> m;
    vector<vi> adj(n);
    vi deg(n, 0);
    rep(i, 0, m){
        int a, b; cin >> a >> b;
        --a; --b;
        deg[a]++;
        deg[b]++;
        adj[a].pb(b);
        if (a != b) adj[b].pb(a);
    }

    int idx = 0;
    vi comps(n, 0);
    vector<vi> odds(n);
    vector<bool> visited(n, false);
    function<void(int)> dfs;
    dfs = [&](int node){
        if (visited[node]) return;
        visited[node] = true;
        comps[idx]++;
        if (deg[node] % 2 == 1){
            odds[idx].pb(node);
        }

        for (int x : adj[node]){
            dfs(x);
        }
    };

    vi oddnodes(n, 0);

    rep(i, 0, n){
        if (deg[i] % 2 == 1){
            oddnodes[i] = 1;
        }
        if (visited[i]) continue;
        dfs(i);
        idx++;
    }

    int ans = m;

    vi oddcomps;
    rep(i, 0, n){
        if (odds[i].size() != 0){
            oddcomps.pb(i);
        }
    }

    rep(i, 0, sz(oddcomps) - 1){
        int j = oddcomps[i];
        int k = oddcomps[i + 1];
        assert(odds[k].size() >= 2);
        int a = odds[j][sz(odds[j]) - 1], b = odds[k][sz(odds[k]) - 1];
        odds[j].pop_back(); odds[k].pop_back();
        adj[a].pb(b);
        adj[b].pb(a);
        oddnodes[a] = 0, oddnodes[b] = 0;
        ans++;
    }

    int prev = -1;

    rep(i, 0, n){
        if (oddnodes[i] == 0) continue;
        if (prev == -1) {
            prev = i;
            continue;
        }

        adj[i].pb(prev);
        adj[prev].pb(i);
        ans++;

        prev = -1;
    }

    assert(prev == -1);

    vector<pii> construct;

    visited = vector<bool>(n, false);
    vector<bool> done(n, false);
    vector<bool> parity(n, 0);
    function<void(int, int)> dfs_tree;
    dfs_tree = [&](int node, int par){
        visited[node] = true;
        sort(all(adj[node]));
        int prev = -1;
        for (int x : adj[node]){
            if (x == node){
                parity[node] = !parity[node];
                construct.pb({node, node});
                continue;
            }

            if (x == par) continue;

            if (x == prev){
                parity[node] = !parity[node];
                construct.pb({node, x});
                continue;
            }

            if (done[x]){
                continue;
            }

            if (visited[x]) {
                parity[node] = !parity[node];
                construct.pb({node, x});
                continue;
            }

            prev = x;

            dfs_tree(x, node);
        }

        if (parity[node]){
            if (par != -1){
                construct.pb({node, par});
            } else {
                ans++;
                construct.pb({node, node});
            }
        } else if (par != -1) {
            construct.pb({par, node});
            parity[par] = !parity[par];
        }

        done[node] = true;
    };

    rep(i, 0, n){
        if (visited[i]) continue;
        dfs_tree(i, -1);
    }

    cout << ans << endl;
    rep(i, 0, construct.size()){
        cout << construct[i].first + 1 << " " << construct[i].second + 1 << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}