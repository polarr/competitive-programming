/**
 * Solution by 1egend (polarity.sh)
 * Date: 2025-02-08
 * Contest: COCI 2016
 * Problem: burza
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

// if he can see the board

// int n, k;
// vector<bool> visited;
// vector<vector<int>> dp;
// vector<vector<int>> adj;
// vector<vector<int>> children;

// void dfs(int node){
//     if (visited[node]){
//         return;
//     }

//     visited[node] = true;

//     bool leaf = true;
//     for (int x : adj[node]){
//         if (!visited[x]){
//             leaf = false;
//             children[node].pb(x);
//         }
//         dfs(x);
//     }

//     if (leaf){
//         rep(i, 0, k + 1){
//             dp[node][i] = 1;
//         }
//     }
// }

// int rec(int node, int left){
//     if (dp[node][left] != -1){
//         return dp[node][left];
//     }

//     if (left == 0){
//         return dp[node][left] = 0;
//     }

//     bool can = false;
//     int cannot = 0;
//     int lastCannot;
//     for (int x : children[node]){
//         if (rec(x, left - 1) == 0){
//             cannot++;
//             lastCannot = x;
//         }
//     }

//     if (cannot == 0 || (cannot == 1 && rec(lastCannot, left) == 1)){
//         return dp[node][left] = 1;
//     }

//     return dp[node][left] = 0;
// }

// void solve(){
//     cin >> n >> k;

//     visited = vector<bool>(n, false);
//     dp = vector<vector<int>>(n, vector<int>(k + 1, -1));
//     adj = vector<vector<int>>(n);
//     children = vector<vector<int>>(n);
//     rep(i, 0, n - 1){
//         int a, b; cin >> a >> b;
//         --a; --b;
//         adj[a].pb(b);
//         adj[b].pb(a);
//     }

//     dfs(0);

//     visited = vector<bool>(n, false);
//     rec(0, k);

//     if (dp[0][k] == 0){
//         cout << "NE" << endl;
//         return;
//     }

//     cout << "DA" << endl;
// }

int n, k;
int leaf = 0;
vector<bool> visited;
vector<vector<int>> depth;
vector<vector<int>> adj;
vector<pii> cover;

pii dfs(int node, int d){
    if (visited[node]){
        return cover[node];
    }

    visited[node] = true;
    depth[d].pb(node);

    if (d == k){
        cover[node] = {leaf, leaf};
        leaf++;
        return cover[node];
    }

    int mn = n + 1;
    int mx = -1;

    for (int x : adj[node]){
        if (visited[x]){
            continue;
        }
        pii stcover = dfs(x, d + 1);
        mn = min(mn, stcover.first);
        mx = max(mx, stcover.second);
    }

    return cover[node] = {mn, mx};
}

void solve(){
    cin >> n >> k;

    visited = vector<bool>(n, false);
    adj = vector<vector<int>>(n);
    depth = vector<vector<int>>(k + 1);
    cover = vector<pii>(n);

    rep(i, 0, n - 1){
        int a, b; cin >> a >> b;
        --a; --b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    if (k * k >= n){
        cout << "DA" << endl;
        return;
    }

    dfs(0, 0);

    if (depth[k].size() == 0){
        cout << "DA" << endl;
        return;
    }

    vector<int> dp(1 << k);
    dp[0] = -1;

    rep(i, 1, 1 << k){
        int mx = -1;
        rep(j, 0, k){
            if ((i & (1 << j)) == 0){
                continue;
            }

            int prevmask = dp[i ^ (1 << j)];
            mx = max(mx, prevmask);

            for (int x : depth[j + 1]){
                pii c = cover[x];
                if (c.first <= prevmask + 1){
                    mx = max(mx, c.second);
                }
            }
        }

        dp[i] = mx;
    }

    if (dp[(1 << k) - 1] == leaf - 1){
        cout << "DA" << endl;
        return;
    }

    cout << "NE" << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}