/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-11-03
 * Contest: CSES Problemset - Additional Problems
 * Problem: 1707
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

void solve(){
    int n, m; cin >> n >> m;

    int ans = INT_MAX;
    
    vector<vector<int>>adj(n);
    vector<int> dist(n, -1);
    vector<int> parent(n, -1);

    for (int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        --a; --b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    for (int i = 0; i < n; i++){
        dist = vector<int>(n, -1);
        parent = vector<int>(n, -1);

        queue<int> q; 
        q.push(i);

        dist[i] = 0;

        while (!q.empty()){
            int n = q.front();
            q.pop();

            for (int node: adj[n]){
                if (dist[node] != -1){
                    if (node != parent[n]){
                        ans = min(ans, dist[node] + dist[n] + 1);
                    }
                    continue;
                }

                parent[node] = n;
                dist[node] = dist[n] + 1;
                q.push(node);
            }
        }
    }

    if (ans == INT_MAX){
        cout << -1 << endl;
        return;
    }

    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}