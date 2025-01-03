/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-12-30
 * Contest: DMOJ utso21
 * Problem: 4
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

vector<bool> keep;
vector<bool> visited;
vector<vector<int>> adj;
map<pair<int, int>, int> edge_map;
vector<bool> degree;

int score = 0;

void dfs(int n, int parent){
    if (visited[n]){
        return;
    }

    visited[n] = true;

    bool isleaf = true;

    if (adj[n].size() == 0){
        return;
    }

    for (auto node : adj[n]){
        if (visited[node]) continue;

        isleaf = false;
        dfs(node, n);
    }

    if (isleaf){
        score++;
        degree[n] = true;
        degree[parent] = !degree[parent];
        keep[edge_map[{n, parent}]] = true;

        return;
    }

    if (parent == -1){
        if (degree[n]){
            score++;
        }
        return;
    }

    score++;

    if (!degree[n]){
        degree[n] = true;
        degree[parent] = !degree[parent];
        keep[edge_map[{n, parent}]] = true;
    }
}

void solve(){
    int n, m; cin >> n >> m;
    
    keep = vector<bool>(m, false);
    visited = vector<bool>(n, false);
    degree = vector<bool>(n, false);
    adj = vector<vector<int>>(n);

    for (int i = 0; i < m; i++){
        int a, b; cin >> a >> b;

        --a; --b;

        edge_map[{a, b}] = i;
        edge_map[{b, a}] = i;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    for (int i = 0; i < n; i++){
        dfs(i, -1);
    }

    int count = 0;

    for (int i = 0; i < m; i++){
        if (!keep[i]){
            count++;
        }
    }

    cout << score << endl;

    cout << count << endl;

    for (int i = 0; i < m; i++){
        if (!keep[i]){
            cout << i + 1 << " ";
        }
    }

    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}