/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-02-20
 * Contest: CSES Problemset - Tree Algorithms
 * Problem: 1131 - Tree Diameter
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

vector<vector<int>> adj;
vector<vector<int>> children;
vector<pair<int, int>> depth;

void dfs_tree(int x){
    for (int y : adj[x]){
        if (children[y].size() == 0){
            children[x].pb(y);
            dfs_tree(y);
        }
    }
}

int dfs(int x){
    int maxDepth = 0;
    int secondDepth = 0;
    
    for (int y : children[x]){
        int d = 1 + dfs(y);
        if (d >= maxDepth){
            secondDepth = maxDepth;
            maxDepth = d;
        } else if (d > secondDepth){
            secondDepth = d;
        }
    }

    depth[x] = make_pair(max(1, maxDepth), secondDepth);

    return max(1, maxDepth);
}

void solve(){
    int n;
    cin >> n;

    adj = vector<vector<int>>(n + 1);
    children = vector<vector<int>>(n + 1);
    depth = vector<pair<int, int>>(n + 1);

    for (int i = 0; i < n - 1; i++){
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    dfs_tree(1);
    dfs(1);

    int ans = 0;
    for (int i = 1; i < n + 1; i++){
        pair<int, int> d = depth[i];
        ans = max(ans, max(0, d.first - 1) + max(0, d.second - 1));
    }

    cout << ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}