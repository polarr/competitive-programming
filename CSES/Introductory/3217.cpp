/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-08-21
 * Contest: CSES Problemset
 * Problem: 3217
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

vector<pii> moves = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {-2, 1}, {2, -1}, {-2, -1}};
void solve(){
    int n; cin >> n; 
    vector<vi> adj(n * n);

    auto edge = [&](int x, int y, int i){
        int from = x * n + y;
        x += moves[i].first;
        y += moves[i].second;
        if (x < 0 || y < 0 || x >= n || y >= n) return;
        int to = x * n + y;

        adj[from].pb(to);
        adj[to].pb(from);
    };

    rep(i, 0, n){
        rep(j, 0, n){
            rep(k, 0, 8){
                edge(i, j, k);
            }
        }
    }

    vector<bool> visited(n * n, false);
    int dist[n * n];
    queue<int> q;
    visited[0] = true;
    dist[0] = 0;
    q.push(0);
    while (!q.empty()){
        int x = q.front();
        q.pop();

        for (int node : adj[x]){
            if (visited[node]) continue;
            visited[node] = true;
            dist[node] = dist[x] + 1;

            q.push(node);
        }
    }

    rep(i, 0, n){
        rep(j, 0, n){
            cout << dist[i * n + j] << " ";
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