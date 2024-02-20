/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-02-20
 * Contest: USACO 2019 December
 * Problem: Silver P3. Milk Visits
**/

#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;

const string iofilename = "milkvisits";
ifstream fin(iofilename + ".in");
ofstream fout(iofilename + ".out");

vector<int> cows = {0};
vector<vector<int>> adj;
vector<vector<int>> children;
vector<bool> visited;
vector<unordered_set<int>> ancestors;
vector<vector<int>> orderedAncestors;
vector<pair<int, int>> pathCows;

void dfs_tree(int x){
    visited[x] = true;

    for (int j : adj[x]){
        if (!visited[j]){
            dfs_tree(j);
            children[x].pb(j);
        }
    }
}

void dfs(int x, pair<int, int> path, unordered_set<int> a, vector<int> oa){
    ancestors[x] = a;
    orderedAncestors[x] = oa;
    oa.pb(x);
    a.insert(x);
    
    if (cows[x] == 0){
        path.first++;
    } else {
        path.second++;
    }

    pathCows[x] = path;

    for (int j : children[x]){
        dfs(j, path, a, oa);
    }
}

// Use fstream (fin, fout) instead of iostream!
void solve(){
    int n, m;
    fin >> n >> m;

    string s;
    fin >> s;

    adj = vector<vector<int>>(n + 1);
    cows = vector<int>(n + 1);
    visited = vector<bool>(n + 1, false);
    children = vector<vector<int>>(n + 1);
    ancestors = vector<unordered_set<int>>(n + 1);
    orderedAncestors = vector<vector<int>>(n + 1);
    pathCows = vector<pair<int, int>>(n + 1);

    for (int i = 1; i < n + 1; i++){
        if (s[i - 1] == 'G'){
            cows[i] = 0;
        } else {
            cows[i] = 1;
        }
    }

    for (int i = 0; i < n - 1; i++){
        int x, y;
        fin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    dfs_tree(1);
    dfs(1, {0, 0}, {}, {});

    string ans = "";

    for (int i = 0; i < m; i++){
        int a, b;
        char c; int milk = 1;
        fin >> a >> b >> c;

        if (c == 'G'){
            milk = 0;
        }

        if (a == b){
            if (cows[a] == milk){
                ans += '1';
            } else {
                ans += '0';
            }
            continue;
        }

        int g = 0, h = 0;
        
        if (ancestors[a].count(b) > 0){
            g = pathCows[a].first - pathCows[b].first;
            h = pathCows[a].second - pathCows[b].second;

            if (cows[b] == 0){
                g++;
            } else {
                h++;
            }
        }
        else if (ancestors[b].count(a) > 0){
            g = pathCows[b].first - pathCows[a].first;
            h = pathCows[b].second - pathCows[a].second;

            if (cows[a] == 0){
                g++;
            } else {
                h++;
            }
        }
        else {
            int c = 1;
            for (int k = orderedAncestors[b].size() - 1; k >= 0; k--){
                if (ancestors[a].count(orderedAncestors[b][k]) > 0){
                    c = orderedAncestors[b][k];
                    break;
                }
            }
            g = pathCows[b].first + pathCows[a].first - 2 * pathCows[c].first;
            h = pathCows[b].second + pathCows[a].second - 2 * pathCows[c].second;
            if (cows[c] == 0){
                g++;
            } else {
                h++;
            }
        }

        if (milk == 0){
            if (g > 0){
                ans += '1';
            } else {
                ans += '0';
            }
        } else {
            if (h > 0){
                ans += '1';
            } else {
                ans += '0';
            }
        }
    }

    fout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    solve();
    return 0;
}