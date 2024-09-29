/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-09-28
 * Contest: Codeforces 2019
 * Problem: E
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

void solve(){
    int n; cin >> n;
    vector<vector<int>> adj(n);
    vector<int> depth(n, 0);
    vector<int> parent(n);
    vector<int> childrenCount(n, 0);
    vector<int> distance(n, -1);

    for (int i = 0; i < n - 1; i++){
        int u, v; cin >> u >> v;
        u--; v--;

        adj[u].pb(v);
        adj[v].pb(u);
    }

    queue<int> bfs;
    bfs.push(0);

    int curr = 0;
    int d = 0;
    int nextMinus = 0;

    distance[0] = d;
    parent[0] = 0;

    while(!bfs.empty()){
        int v = bfs.front();
        bfs.pop();
        if (distance[v] != d){
            depth[d] = curr;
            d++;
            curr -= nextMinus;
            nextMinus = 0;
        }

        curr++;

        bool isLeaf = true;
        for (int node : adj[v]){
            if (distance[node] != -1){
                continue;
            }

            isLeaf = false;
            childrenCount[v]++;
            parent[node] = v;
            distance[node] = distance[v] + 1;
            bfs.push(node);
        }

        if (isLeaf){
            nextMinus++;
            int p = parent[v];
            while(p != parent[p]){
                childrenCount[p]--;
                if (childrenCount[p] == 0){
                    nextMinus++;
                    p = parent[p];
                } else {
                    break;
                }
            }
        }
    }

    depth[d] = curr;

    int ans = 0;
    for (int i = 0; i < n; i++){
        //cout << depth[i] << " ";
        ans = max(ans, depth[i]);
    }

    //cout << endl;

    cout << n - ans << endl;
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