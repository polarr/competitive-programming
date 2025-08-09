/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-08-08
 * Contest: Codeforces 2127
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
    int n, k; cin >> n >> k;

    vl w(n);
    vi color(n);
    rep(i, 0, n) {
        cin >> w[i];
    }
    rep(i, 0, n){
        cin >> color[i];
    }

    vector<vi> adj(n);
    rep(i, 0, n - 1){
        int a, b; cin >> a >> b;
        --a; --b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    vector<set<int>> colors(n);

    ll ans = 0;

    vi assign(n, 0);

    function<void(int, int)> dfs;
    dfs = [&](int node, int par){
        int dup = -1;
        bool bad = false;

        for (int x : adj[node]){
            if (x == par) continue;
            dfs(x, node);

            if (colors[node].size() < colors[x].size()){
                swap(colors[node], colors[x]);
            }

            for (int el : colors[x]){
                if (colors[node].contains(el)){
                    if (dup != -1 && dup != el){
                        bad = true;
                    }

                    dup = el;
                    continue;
                }

                colors[node].insert(el);
            }
        }

        cerr << node << " " << dup << endl;

        if (color[node] != 0){
            int c = color[node];
            if (bad || (dup != -1 && dup != c)){
                ans += w[node];
            }

            colors[node].insert(c);
        } else {
            if (!colors[node].empty()) assign[node] = *colors[node].begin();
            if (bad){
                ans += w[node];
            } else {
                if (dup != -1) assign[node] = dup;
            }
        }
    };

    dfs(0, -1);

    vi ansColor(n, 0);

    function<void(int, int)> dfs_color;
    dfs_color = [&](int node, int par){
        if (color[node] != 0){
            ansColor[node] = color[node];
        }
        else if (assign[node] == 0){
            if (par == -1) ansColor[node] = 1;
            else ansColor[node] = ansColor[par];
        } else {
            ansColor[node] = assign[node];
        }

        for (int x : adj[node]){
            if (x == par) continue;
            dfs_color(x, node);
        }
    };

    dfs_color(0, -1);

    cout << ans << endl;

    for (int c : ansColor){
        cout << c << " ";
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