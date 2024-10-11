/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-10-10
 * Contest: CSES Problemset - Tree Algorithms
 * Problem: 1132
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

vector<vector<int>> adj;    
vector<int> parent;
vector<vector<pair<int, int>>> ans;
vector<vector<pair<int, int>>> max_depth;
vector<vector<int>> children;

void dfs_depth(int n){
    vector<pair<int,int>> d = {{0, -1}, {0, -1}};

    for (int node : adj[n]){
        if (parent[node] != -1){
            continue;
        }

        parent[node] = n;
        children[n].pb(node);
        dfs_depth(node);

        pair<int, int> dd = max_depth[node][0];
        ++dd.first;

        if (dd.first >= d[0].first){
            d[1] = d[0];
            d[0] = {dd.first, node};
        } else if (dd.first >= d[1].first){
            d[1] = {dd.first, node};
        }
    }

    max_depth[n] = d;
}

void dfs(int n){
    if (n != 0){
        int other = 0;
        if (ans[parent[n]][1].second != n){
            other = ans[parent[n]][1].first;
        }
        if (ans[parent[n]][0].second != n){
            other = ans[parent[n]][0].first;
        }

        ++other;

        if (max_depth[n][0].first > other){
            if (max_depth[n][1].first > other){
                ans[n] = max_depth[n];
            } else {
                ans[n] = {max_depth[n][0], {other, parent[n]}};
            }
        } else {
            ans[n] = {{other, parent[n]}, {0, -1}};
        }
    }

    for (int node : children[n]){
        dfs(node);
    }
}

void solve(){
    int n; cin >> n;
    adj = vector<vector<int>>(n);
    parent = vector<int>(n, -1);
    max_depth = vector<vector<pair<int, int>>>(n);
    ans =  vector<vector<pair<int, int>>>(n);
    children = vector<vector<int>>(n);

    for (int i = 0; i < n - 1; i++){
        int a, b; cin >> a >> b;
        --a; --b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    parent[0] = 0;

    dfs_depth(0);

    ans[0] = max_depth[0];
    dfs(0);

    for (int i = 0; i < n; i++){
        cout << ans[i][0].first << " ";
    }

    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}