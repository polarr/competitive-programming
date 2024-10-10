/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-10-10
 * Contest: CSES Problemset - Tree Algorithms
 * Problem: 2179
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

vector<vector<int>> adj;
vector<pair<int, int>> ans;
vector<bool> parity;
vector<int> parent;
vector<int> depth;
vector<vector<int>> children;

void dfs_tree(int n, int d){
    depth[n] = d;

    for (int node : adj[n]){
        if (parent[node] != -1){
            if (node != parent[n] && depth[node] + 1 < depth[n]){
                ans.pb({node, n});
                parity[node] = !parity[node];
            }
            continue;
        }

        parent[node] = n;
        children[n].pb(node);

        dfs_tree(node, d + 1);
    }
}

void dfs(int n, int s){
    if (n != s && children[n].size() == 0){
        parity[parent[n]] = !parity[parent[n]];
        ans.pb({parent[n], n});
        return;
    }

    for (int child : children[n]){
        dfs(child, s);
    }

    if (n == s){
        return;
    }

    if (!parity[n]){
        parity[parent[n]] = !parity[parent[n]];
        ans.pb({parent[n], n});
    } else {
        ans.pb({n, parent[n]});
    }
}

void solve(){
    int n, m; cin >> n >> m;

    adj = vector<vector<int>> (n);
    for (int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        --a; --b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    parity = vector<bool>(n, false);
    depth = vector<int>(n, -1);
    children = vector<vector<int>> (n);
    parent = vector<int>(n, -1);
    parent[0] = 0;

    vector<int> starts;

    for (int i = 0; i < n; i++){
        if (depth[i] == -1){
            parent[i] = i;
            starts.pb(i);
            dfs_tree(i, 0);
        }
    }

    for (int i = 0; i < starts.size(); i++){
        dfs(starts[i], starts[i]);

        if (parity[starts[i]]){
            cout << "IMPOSSIBLE" << endl;
            return;
        }
    }

    for (int i = 0; i < ans.size(); i++){
        cout << ans[i].first + 1 << " " << ans[i].second + 1 << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}