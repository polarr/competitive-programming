/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-10-02
 * Contest: Codeforces 2029
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
    vector<set<int>> adj(n);
    rep(i, 0, m){
        int a, b; cin >> a >> b;
        --a; --b;
        adj[a].insert(b);
        adj[b].insert(a);
    }

    int root = 0;

    vector<array<int, 3>> ans;


    vector<pii> rem;
    vector<bool> visited(n, false), parent(n, -2), back(n, false);
    function<void(int, int)> dfs_tree, dfs_solve;
    dfs_tree = [&](int node, int par){
        visited[node] = true;
        parent[node] = par;
        for (int x : adj[node]){
            if (x == par || !visited[x]){
                continue;
            }

            back[node] = !back[node];
            rem.pb({x, node});
            if (x != root){
                ans.pb({root, x, node});
                back[x] = !back[x];
            }
        }

        for (int x : adj[node]){
            if (!visited[x]){
                dfs_tree(x, node);
                if (back[x]){
                    rem.pb({x, node});
                    if (node == root){    
                        continue;
                    }
                    ans.pb({root, node, x});
                    back[node] = !back[node];
                    back[x] = false;
                }
            }
        }
    };  

    rep(i, 0, n){
        if (!visited[i]){
            root = i;
            dfs_tree(i, -1);            
        }
    }

    for (auto &[x, node] : rem){
        adj[node].erase(x);
        adj[x].erase(node);
    }  
    
    vi cnt(n, 0);
    vi roots;
    visited = vector<bool>(n, false);
    vector<bool> res(n, false);
    dfs_solve = [&](int node, int par){
        cnt[root]++;
        visited[node] = true;
        for (int x : adj[node]){
            if (x == par) continue;
            dfs_solve(x, node);
        }
    };

    int a = -1, b = -1;

    rep(i, 0, n){
        if (!visited[i]){
            root = i;
            roots.pb(root);
            dfs_solve(i, -1);
            if (sz(adj[root]) > 0){
                res[root] = true;
                a = root;
                b = *adj[root].begin();
            }
        }
    }

    if (a != -1){
        for (int root : roots){
            if (res[root]) continue;
            ans.pb({root, a, b});
            b = a;
            a = root;
        }
    }
    
    cout << sz(ans) << endl;
    for(array<int, 3> a : ans){
        cout << a[0] + 1 << " " << a[1] + 1 << " " << a[2] + 1 << endl;
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