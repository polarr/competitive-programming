/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-10-05
 * Contest: ICPC NAQ 2024
 * Problem: D
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

vector<int> color(1e5);
vector<vector<int>> ans(1e5);
vector<vector<int>> adj(1e5);
vector<vector<int>> children(1e5);
vector<int> parent(1e5, -1);

void dfs_parent(int n){
    for (int node : adj[n]){
        if (parent[node] != -1){
            continue;
        }

        parent[node] = n;
        children[n].pb(node);
        dfs_parent(node);
    }
}

vector<int> dfs(int n){
    vector<int> a(1e5, 0);
    a[color[n]]++;
    for (int node : children[n]){
        vector<int> b = dfs(node);

        for (int i = 0; i < a.size(); i++){
            a[i] += b[i];
        }
    }

    ans[n] = a;

    return a;
}

void solve(){
    int n; cin >> n;
    vector<int> totalcolor(n, 0);

    for (int i = 0; i < n; i++){
        int c; cin >> c;
        --c;
        color[i] = c;
        totalcolor[c]++;
    }

    vector<pair<int, int>> edges;

    for (int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        --a; --b;
        edges.pb({a, b});
        adj[a].pb(b);
        adj[b].pb(a);
    }

    parent[0] = 0;

    dfs_parent(0);

    dfs(0);

    for (int i = 0; i < n - 1; i++){
        pair<int, int> ed = edges[i];
        if (parent[ed.first] != ed.second){
            swap(ed.first, ed.second);
        }

        vector<int> c = ans[ed.first];
        ull a = 0;
        for (int j = 0; j < n; j++){
            a += (ull) (totalcolor[j] - c[j]) * (ull) c[j];
        }

        cout << a << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}