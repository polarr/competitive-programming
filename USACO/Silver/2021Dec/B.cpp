/**
 * Solution by 1egend
 * Date: 2021-12-20
 * Contest: USACO 2021 December
 * Problem: Silver 
**/

#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;

const string iofilename = "";
ifstream fin(iofilename + ".in");
ofstream fout(iofilename + ".out");

int n, m;
vector<int> adj[MAX_N];
bool visited[MAX_N];
set<int> start;
set<int> final;

void fdfs(int node){
    final.insert(node);
    visited[node] = true;
    for(int next : adj[node]){
        if(!visited[next]){
            fdfs(next);
        }
    }
}

void sdfs(int node){
    start.insert(node);
    visited[node] = true;
    for(int next : adj[node]){
        if(!visited[next]){
            sdfs(next);
        }
    }
}

// Use fstream (fin, fout) instead of iostream!
void solve(){
    fill(adj, adj + MAX_N, vector<int>{});
    fill(visited, visited + MAX_N, false);
    start = {};
    final = {};
    cin >> n >> m;

    for (int i = 0; i < m; ++i){
        int a, b;
        cin >> a >> b;
        --a; --b;

        adj[a].pb(b);
        adj[b].pb(a);
    }

    fdfs(n - 1);
    fill(visited, visited + MAX_N, false);
    sdfs(0);

    ull ans = ULLONG_MAX;
    for (int node: final){
        auto up = start.lower_bound(node);
        int down = *(--start.upper_bound(node));
        if (up != start.end()){
            double diff = *up - node;
            ans = min<ull>(ans, floor(diff/2.0) * floor(diff/2.0) + ceil(diff/2.0) * ceil(diff/2.0));
        }

        double diff = node - down;
        ans = min<ull>(ans, floor(diff/2.0) * floor(diff/2.0) + ceil(diff/2.0) * ceil(diff/2.0));
    }

    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i){
        solve();
    }
    return 0;
}