/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-02-19
 * Contest: USACO 2017 February Contest
 * Problem: Silver P3. Why Did the Cow Cross the Road III
**/

// Windows Security flags this for some reason

#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;

const string iofilename = "countcross";
ifstream fin(iofilename + ".in");
ofstream fout(iofilename + ".out");

vector<vector<vector<pair<int, int>>>> adj;
vector<vector<bool>> cow;
vector<vector<bool>> visited;
vector<int> comp;
vector<pair<int, int>> cardinal = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int c = 0;

bool floodfill(int i, int j){
    if (i < 0 || i >= visited.size() || j < 0 || j >= visited.size() || visited[i][j]){
        return false;
    }

    visited[i][j] = true;
    if (cow[i][j]){
        c++;
    }

    
    for (int t = 0; t < cardinal.size(); t++){
        int ii = i + cardinal[t].first;
        int jj = j + cardinal[t].second;
        bool valid = true;
        for (int k = 0; k < adj[i][j].size(); k++){
            if (adj[i][j][k].first == ii && adj[i][j][k].second == jj){
                valid = false;
                break;
            }
        }

        if (valid){
            floodfill(ii, jj);
        }
    }

    return true;
}

// Use fstream (fin, fout) instead of iostream!
void solve(){
    int n, k, r;
    fin >> n >> k >> r;

    adj = vector<vector<vector<pair<int, int>>>> (n, vector<vector<pair<int, int>>>(n));
    cow = vector<vector<bool>>(n, vector<bool>(n, false));
    visited = vector<vector<bool>>(n, vector<bool>(n, false));

    for (int i = 0; i < r; i++){
        int a, b, x, y;
        fin >> a >> b >> x >> y;
        a--; b--; x--; y--;
        adj[a][b].pb(make_pair(x, y));
        adj[x][y].pb(make_pair(a, b));
    }

    for (int i = 0; i < k; i++){
        int a, b;
        fin >> a >> b;
        a--; b--;
        cow[a][b] = true;
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (floodfill(i, j)){
                comp.pb(c);
                c = 0;
            }
        }
    }

    ll sum = 0;
    ll sqSum = 0;
    for (int i = 0; i < comp.size(); i++){
        sum += comp[i];
        sqSum += comp[i] * comp[i];
    }

    fout << (sum * sum - sqSum)/2 << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    solve();
    return 0;
}