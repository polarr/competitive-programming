/**
 * Solution by 1egend (polarity.sh)
 * Date: 2025-02-11
 * Contest: IOI 2007
 * Problem: training
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

int n, m; 
vector<vector<int>> adj;
vector<vector<int>> cost;
vector<bool> visited;
vector<vector<int>> branch;
vector<int> branchNum;
vector<int> bipartition;
vector<int> dp;

void dfs(int node, bool d, int b){
    if (visited[node]){
        return;
    }

    visited[node] = true;
    bipartition[node] = d;
    branch[b].pb(node);
    branchNum[node] = b;

    for (int x : adj[node]){
        dfs(x, !d, b);
    }
}

void solve(){
    int n, m; cin >> n >> m;

    adj = vector<vector<int>>(n);
    vector<array<int, 3>> edges;
    cost = vector<vector<int>>(n, vi(n, 0));
    visited = vector<bool>(n, false);
    branch = vector<vector<int>>(10);
    branchNum = vector<int>(n, -1);
    bipartition = vector<int>(n, 0);
    dp = vector<int>(1 << 10, 0);

    int total = 0;

    rep(i, 0, m){
        int a, b, c; cin >> a >> b >> c;
        --a; --b;
        if (c == 0){
            adj[a].pb(b);
            adj[b].pb(a);
        } else {
            total += c;
            cost[a][b] = c;
            cost[b][a] = c;
            edges.pb({a, b, c});
            edges.pb({b, a, c});
        }
    }

    // root at 0
    visited[0] = true;
    branchNum[0] = -1;
    bipartition[0] = 0;

    int bcount = 0;
    for (int x : adj[0]){
        dfs(x, 1, bcount);
        bcount++;
    }

    dp[0] = 0;
    vector<int> which(1 << bcount);
    rep(i, 0, bcount){
        which[1 << i] = i;
    }

    rep(i, 0, 1 << bcount){
        int prevmask = i & (i - 1);
        int lsb = which[i ^ prevmask];
        int mx = dp[prevmask];

        for (array<int, 3> edge : edges){
            int a = edge[0], b = edge[1], c = edge[2];
            if (bipartition[a] != bipartition[b]){
                continue;
            }

            if (branchNum[a] == lsb && branchNum[b] == -1){
                mx = max(mx, dp[prevmask] + c);
            }
        }

        for (array<int, 3> edge : edges){
            int a = edge[0], b = edge[1], c = edge[2];
            if (a == 0 || b == 0){
                continue;
            }
            if (bipartition[a] != bipartition[b]){
                continue;
            }

            if (branchNum[a] == lsb){
                if ((i & (1 << branchNum[b]))){
                    int prev = i ^ (1 << branchNum[b]);
                    mx = max(mx, c + dp[prev]);
                }
            }
        }

        dp[i] = mx;
    }

    cout << total - dp[(1 << bcount) - 1] << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}