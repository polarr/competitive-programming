/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-01-30
 * Contest: USACO 2019 February Contest
 * Problem: Silver P3. The Great Revegetation
**/

#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;

const string iofilename = "revegetate";
ifstream fin(iofilename + ".in");
ofstream fout(iofilename + ".out");

vector<vector<pair<int, bool>>> adj;
vector<int> value;

bool dfs(int v, int val){
    if (value[v] != -1){
        return value[v] == val;
    }

    value[v] = val;
    int valid = true;
    int diff = (val == 1 ? 0:1);
    for (pair<int, bool> j : adj[v]){
        int assign = val;
        if (!j.second){
            assign = diff;
        }

        if (!dfs(j.first, assign)){
            valid = false;
        }
    }

    return valid;
}

// Use fstream (fin, fout) instead of iostream!
void solve(){
    int n, m;
    fin >> n >> m;

    value = vector<int>(n + 1, -1);
    adj = vector<vector<pair<int, bool>>>(n + 1);

    for (int i = 0; i < m; i++){
        char t;
        int a, b;
        fin >> t >> a >> b;
        bool same = (t == 'S');
        adj[a].pb(make_pair(b, same));
        adj[b].pb(make_pair(a, same));
    }

    int ans = 0;
    for (int i = 1; i < n + 1; i++){
        if (value[i] == -1){
            ans++;
            if (!dfs(i, 1)){
                fout << 0 << endl;
                return;
            }
        }
    }
    
    fout << 1;
    for (int i = 0; i < ans; i++){
        fout << 0;
    }
    fout << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    solve();
    return 0;
}