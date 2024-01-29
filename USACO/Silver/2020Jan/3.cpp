/**
 * Solution by 1egend
 * Date: 2024-01-29
 * Contest: USACO 2020 January
 * Problem: Silver P3. Wormhole Sort
**/

#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;

const string iofilename = "wormsort";
ifstream fin(iofilename + ".in");
ofstream fout(iofilename + ".out");

vector<int> visited;
vector<vector<int>> adj;

bool dfs(int v, int count){
    if (visited[v] != -1){
        return false;
    }

    visited[v] = count;

    for (int i : adj[v]){
        dfs(i, count);
    }

    return true;
}

// Use fstream (fin, fout) instead of iostream!
void solve(){
    int n, m;
    fin >> n >> m;

    vector<pair<int, int>> swaps;
    vector<tuple<int, int, int>> wormholes;

    for (int i = 1; i < n + 1; i++){
        int p;
        fin >> p;
        if (p != i){
            swaps.pb(make_pair(i, p));
        }
    }

    if (swaps.size() == 0){
        fout << -1 << endl;
        return;
    }

    for (int i = 0; i < m; i++){
        int a, b, w;
        fin >> a >> b >> w;
        wormholes.pb(make_tuple(w, a, b));
    }
    sort(wormholes.begin(), wormholes.end(), greater{});

    int low = 0;
    int high = m;
    int ans = 0;
    while (low < high){
        int middle = (low + high)/2;
        adj = vector<vector<int>>(n + 1);

        for (int i = 0; i <= middle; i++){
            tuple<int, int, int> wormhole = wormholes[i];
            adj[get<1>(wormhole)].pb(get<2>(wormhole));
            adj[get<2>(wormhole)].pb(get<1>(wormhole));
        }

        visited = vector<int>(n + 1, -1);
        int count = 0;
        for (int v = 1; v < n + 1; v++){
            if (dfs(v, count)){
                count++;
            }
        }

        int success = true;
        for (pair<int, int> p : swaps){
            if (visited[p.first] != visited[p.second]){
                success = false;
                break;
            }
        }

        if (success){
            ans = middle;
            high = middle;
        } else {
            low = middle + 1;
        }
    }

    fout << get<0>(wormholes[low]) << endl;
    
    /**
    for (int i = 0; i < m; i++){
        tuple<int, int, int> wormhole = wormholes[i];
        adj[get<1>(wormhole)].pb(get<2>(wormhole));
        adj[get<2>(wormhole)].pb(get<1>(wormhole));
        if (i == m - 1 || get<0>(wormhole) != get<0>(wormholes[i + 1])){
            visited = vector<int>(n + 1, -1);
            int count = 0;
            for (int v = 1; v < n + 1; v++){
                if (dfs(v, count)){
                    count++;
                }
            }

            int success = true;
            for (pair<int, int> p : swaps){
                if (visited[p.first] != visited[p.second]){
                    success = false;
                    continue;
                }
            }

            if (success){
                fout << get<0>(wormhole) << endl;
                return;
            }
        }
    }
    */
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    solve();
    return 0;
}