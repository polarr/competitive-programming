/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-10-10
 * Contest: CSES Problemset - Tree Algorithms
 * Problem: 1133
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
vector<int> c;
vector<ull> ans;

pair<ull, int> dfs(int n){
    ull d = 0; int count = 1;

    for (int node : adj[n]){
        if (parent[node] != -1){
            continue;
        }

        parent[node] = n;

        pair<ull, int> s = dfs(node);
        d += s.first + s.second;
        count += s.second;
    }

    ans[n] = d;
    c[n] = count;
    return {d, count};
}

void dfs2(int n){
    if (n != 0){
        ans[n] = ans[parent[n]] + parent.size() - 2 * c[n];
    }

    for (int node : adj[n]){
        if (node == parent[n]){
            continue;
        }

        dfs2(node);
    }
}

void solve(){
    int n; cin >> n;
    adj = vector<vector<int>>(n);
    parent = vector<int>(n, -1);
    c = vector<int>(n, 0);
    ans = vector<ull>(n);

    for (int i = 0; i < n - 1; i++){
        int a, b; cin >> a >> b;
        --a; --b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    parent[0] = 0;

    dfs(0);
    dfs2(0);

    for (int i = 0; i < n; i++){
        cout << ans[i] << " ";
    }

    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}