/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-05-28
 * Contest: Codeforces 1000
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

void solve(){
    int n, q; cin >> n >> q;

    int lg = log2(n) + 1;
    
    vl arr(n);
    rep(i, 0, n){
        cin >> arr[i];
    }

    vector<vector<pair<ll, int>>> adj(n);
    vl edge(n, 0);
    rep(i, 0, n - 1){
        int a, b; ll w; cin >> a >> b >> w;
        --a; --b;
        adj[a].pb({w, b});
        adj[b].pb({w, a});
    }

    vi parent(n), depth(n, 0);
    vector<map<int, ll>> dp(n);
    vector<vector<pair<int, ll>>> jump(n, vector<pair<int, ll>>(lg, {-1, 0}));

    auto comp = [&](int node, int par){
        ll e = edge[node];
        if (depth[node] < depth[par]){
            e = edge[par];
        }
        return max(0LL, arr[node] - e * 2 + dp[node][par]);
    };

    function<void(int, int)> dfs1, dfs2;
    dfs1 = [&](int x, int par){
        ll mx = 0;
        parent[x] = par;
        for (auto [w, node] : adj[x]){
            if (node == par){
                continue;
            }

            depth[node] = depth[x] + 1;
            edge[node] = w;
            dfs1(node, x);
            mx += comp(node, x);
        }

        dp[x][par] = mx;
    };

    dfs1(0, -1);
    
    dfs2 = [&](int x, int par){
        ll mx = dp[x][par];
        for (auto [w, node] : adj[x]){
            if (node == par){
                continue;
            }

            ll up = 0;
            if (par != -1) up = comp(par, x);
            dp[x][node] = mx + up - comp(node, x);
            jump[node][0] = {x, arr[x] - w + dp[x][node]};

            dfs2(node, x);
        }
    };

    dfs2(0, -1);
    
    auto combine = [&](pair<int, ll> &jp1, pair<int, ll> &jp2){
        if (jp1.first == -1){
            return jp2;
        }

        return pair<int, ll>{
            jp2.first,
            jp1.second + jp2.second - comp(parent[jp1.first], jp1.first)
        };
    };

    rep(l, 1, lg){
        rep(i, 0, n){
            pair<int, ll> jp1 = jump[i][l - 1];
            if (jp1.first == -1) continue;
            pair<int, ll> jp2 = jump[jp1.first][l - 1];
            if (jp2.first == -1) continue;
            jump[i][l] = combine(jp1, jp2);
        }
    }

    vi pow2(lg);
    rep(i, 0, lg){
        pow2[i] = (1 << i);
    }

    rep(i, 0, q){
        int a, b; cin >> a >> b;
        --a; --b;

        if (a == b){
            ll up = 0;
            if (parent[a] != -1) up = comp(parent[a], a);
            cout << arr[a] + dp[a][parent[a]] + up << endl;
            continue;
        }

        if (depth[a] > depth[b]){
            swap(a, b);
        }

        int d = depth[b] - depth[a], at2 = b;

        pair<int, ll> curr1, curr2;
        curr1 = curr2 = {-1, 0};
        
        rep(j, 0, lg){
            if (d & pow2[j]){
                curr2 = combine(curr2, jump[at2][j]);
                at2 = jump[at2][j].first;
            }
        }

        if (at2 == a){
            cout << curr2.second + arr[b] + dp[b][parent[b]] << endl;
            continue;
        }

        int at1 = a;
        for (int j = lg - 1; j >= 0; j--){
            if (jump[at1][j].first != jump[at2][j].first){
                curr1 = combine(curr1, jump[at1][j]);
                curr2 = combine(curr2, jump[at2][j]);

                at1 = jump[at1][j].first;
                at2 = jump[at2][j].first;
            }
        }

        int b1 = at1, b2 = at2;

        curr1 = combine(curr1, jump[at1][0]);
        curr2 = combine(curr2, jump[at2][0]);

        int lca = curr1.first;
        cout << curr1.second + curr2.second + arr[a] + arr[b] + dp[a][parent[a]] + dp[b][parent[b]] - arr[lca] - dp[lca][b1] - comp(b1, lca) << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}