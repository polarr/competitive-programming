/**
 * Solution by 1egend (polarity.sh)
 * Date: 
 * Contest: 
 * Problem: 
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

map<pair<int, int>, int> color;
vector<int> ans;
vector<vector<int>> adj;
vector<int> visited;

// just 2-color dfs tree by depth
void dfs(int node, bool red){
    visited[node] = true;

    for (int v : adj[node]){
        if (visited[v]){
            continue;
        }
        int a = node;
        int b = v;
        if (a > b){
            swap(a, b);
        }

        pair<int, int> p = make_pair(a, b);

        ans[color[p]] = (red ? 1:2);
        dfs(v, !red);
    }
}

void solve(){
    int n, m;
    cin >> n >> m;
    
    ans = vector<int>(m + 1, 0);
    adj = vector<vector<int>>(n + 1);
    visited = vector<int>(n + 1, false);

    for (int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        if (u > v){
            swap(u, v);
        }

        adj[u].pb(v);
        adj[v].pb(u);

        pair<int, int> p = make_pair(u, v);

        color[p] = i + 1;
    }


    for (int i = 1; i < n + 1; i++){
        if (!visited[i]){
            dfs(i, false);
        }
    }

    for (int i = 1; i < m + 1; i++){
        if (ans[i] == 0){
            cout << "G";
        } else if (ans[i] == 1){
            cout << "R";
        } else if (ans[i] == 2){
            cout << "B";
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}