/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-01-27
 * Contest: CSES Problem Set
 * Problem: Graph Algorithms - Flight Routes Check
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

vector<bool> visited;
vector<bool> nvisited;
vector<vector<int>> adj;
vector<vector<int>> nadj;

void dfs(int v){
    if (visited[v]){
        return;
    }

    visited[v] = true;

    for (int i : adj[v]){
        dfs(i);
    }
}

void ndfs(int v){
    if (nvisited[v]){
        return;
    }

    nvisited[v] = true;
    
    for (int i : nadj[v]){
        ndfs(i);
    }
}

void solve(){
    int n, m;
    cin >> n >> m;
    visited = vector<bool>(n + 1, false);
    nvisited = vector<bool>(n + 1, false);
    adj = vector<vector<int>>(n + 1);
    nadj = vector<vector<int>>(n + 1);

    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        nadj[b].pb(a);
    }

    dfs(1);
    ndfs(1);

    for (int i = 2; i < n + 1; i++){
        if (!visited[i]){
            cout << "NO" << endl;
            cout << 1 << " " << i << endl;
            return;
        }

        if (!nvisited[i]){
            cout << "NO" << endl;
            cout << i << " " << 1 << endl;
            return;
        }
    }

    cout << "YES";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}