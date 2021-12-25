/**
 * Solution by 1egend
 * Date: 2021-12-11
 * Contest: USACO 2018 January
 * Problem: Silver P3. MooTube
**/

#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;

const string iofilename = "mootube";
ifstream fin(iofilename + ".in");
ofstream fout(iofilename + ".out");

struct Edge {
    int to, weight;
    Edge(int dest, int w):
    to(dest), weight(w)
    {}
};

int n, ans = 0;
vector <Edge> adj[5000];
bool visited[5000];

void bfs(int start, int k){
    visited[start] = true;
    queue<int> qq;
    qq.push(start);
    while(!qq.empty()){
        int l = qq.front();
        qq.pop();
        for (Edge e : adj[l]){
            if (!visited[e.to] && e.weight >= k){
                visited[e.to] = true;
                ++ans;
                qq.push(e.to);
            }
        }
    }
}

// Use fstream (fin, fout) instead of iostream!
void solve(){
    int q;
    fin >> n >> q;

    for (int i = 0; i < n - 1; ++i){
        int a, b, w;
        fin >> a >> b >> w;

        --a; --b;
        adj[a].pb(Edge(b, w));
        adj[b].pb(Edge(a, w));
    }

    for (int i = 0; i < q; ++i){
        ans = 0;
        fill(visited, visited + 5000, 0);
        
        int k, v;
        fin >> k >> v;
        bfs(--v, k);

        fout << ans << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    solve();
    return 0;
}