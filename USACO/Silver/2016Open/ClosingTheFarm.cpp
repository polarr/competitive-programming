/**
 * Solution by 1egend
 * Date: 2021-12-12
 * Contest: USACO 2016 US Open
 * Problem: Silver P3. Closing the Farm
**/

#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;

const string iofilename = "closing";
ifstream fin(iofilename + ".in");
ofstream fout(iofilename + ".out");

unordered_set <int> adj[3000];
bool visited[3000];
int connected;

void dfs(int node){
    ++connected;
    visited[node] = true;
    for (int next : adj[node]){
        if (!visited[next]){
            dfs(next);
        }
    }
}

// Use fstream (fin, fout) instead of iostream!
void solve(){
    int n, m;
    fin >> n >> m;

    for (int i = 0; i < m; ++i){
        int a, b;
        fin >> a >> b;
        --a; --b;

        adj[a].insert(b);
        adj[b].insert(a);
    }
    
    queue<int> q;

    for (int i = 0; i < n; ++i){
        int v;
        fin >> v;
        --v;

        q.push(v);
    }

    for (int i = 0; i < n; ++i){
        int v = q.front();

        connected = 0;
        fill(visited, visited + 3000, 0);
        dfs(v);

        if (connected == n - i){
            fout << "YES" << endl;
        } else {
            fout << "NO" << endl;
        }
        
        for (int ii : adj[v]){
            adj[ii].erase(v);
        }

        adj[v] = {};

        q.pop();
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    solve();
    return 0;
}