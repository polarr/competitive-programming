/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-10-08
 * Contest: USACO 2019 December Silver
 * Problem: 3 - Milk Visits
**/

#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

const string iofilename = "milkvisits";
ifstream fin(iofilename + ".in");
ofstream fout(iofilename + ".out");

vector<bool> breed;
vector<vector<int>> adj;
vector<int> comp;

void dfs(int n, int c){
    if (comp[n] != -1){
        return;
    }

    comp[n] = c;

    for (int node : adj[n]){
        if (breed[node] != breed[n]){
            continue;
        }
        dfs(node, c);
    }
}

// Use fstream (fin, fout) instead of iostream!
void solve(){
    int n, m; fin >> n >> m;

    breed = vector<bool>(n);
    adj = vector<vector<int>>(n);
    comp = vector<int>(n, -1);

    string s; fin >> s;

    for (int i = 0; i < n; i++){
        breed[i] = (s[i] == 'G');
    }

    for (int i = 0; i < n - 1; i++){
        int x, y; fin >> x >> y;
        --x; --y;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    for (int i = 0; i < n; i++){
        dfs(i, i);
    }

    string ans = "";

    for (int i = 0; i < m; i++){
        int x, y; fin >> x >> y;
        --x; --y;
        char s; fin >> s;
        bool b = (s == 'G');

        if (comp[x] != comp[y] || breed[x] == b){
            ans += "1";
            continue;
        }

        ans += "0";
    }
    
    fout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    fin.tie(0); fout.tie(0);
    
    solve();
    return 0;
}