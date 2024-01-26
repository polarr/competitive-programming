/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-01-15
 * Contest: CSES Problem Set
 * Problem: Graph Algorithms - Message Route
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> dist(n + 1, INT_MAX);
    vector<int> parent(n + 1, 0);
    vector<vector<int>> adj(n + 1);
    dist[1] = 1;
    for (int i = 0; i < m; i ++){
        int a, b;
        cin >> a >> b;
        adj[a].pb(b); adj[b].pb(a);
    }
    queue<int> q;
    q.push(1);
    bool found = false;

    while (!found && !q.empty()){
        int x = q.front();
        q.pop();
        for (int i : adj[x]){
            if (dist[i] == INT_MAX){
                dist[i] = dist[x] + 1;
                parent[i] = x;
                q.push(i);
            }
            if (i == n){
                found = true;
                break;
            }
        }
    }

    if (dist[n] == INT_MAX){
        cout << "IMPOSSIBLE";
    } else {
        cout << dist[n] << endl;
        int current = n;
        vector<int> path;
        while (current != 1){
            path.pb(current);
            current = parent[current];
        }
        path.pb(1);
        reverse(path.begin(), path.end());
        for (int i = 0; i < path.size(); i++){
            cout << path[i] << " ";
        }
        cout << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}