/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-10-30
 * Contest: BOI 2013
 * Problem: tracks
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

vector<pair<int, int>> cardinal = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
vector<vector<int>> grid;
vector<vector<int>> component;

void floodfill(int i, int j, int n, int l){
    if (grid[i][j] != l || component[i][j] != 0){
        return;
    }

    component[i][j] = n;

    for (pair<int, int> t : cardinal){
        floodfill(i + t.first, j + t.second, n, l);
    }
}

void solve(){
    int h, w; cin >> h >> w;
    grid = vector<vector<int>>(h + 2, vector<int>(w + 2, 0));
    component = grid;
    for (int i = 0; i < h; i++){
        string s; cin >> s;
        for (int j = 0; j < w; j++){
            char t = s[j];

            if (t == 'F'){
                grid[i + 1][j + 1] = 2;
            } else if (t == 'R'){
                grid[i + 1][j + 1] = 1;
            }
        }
    }

    int k = 1;

    for (int i = 1; i < h + 1; i++){
        for (int j = 1; j < w + 1; j++){
            if (component[i][j] == 0 && grid[i][j] != 0){
                floodfill(i, j, k, grid[i][j]);
                k++;
            }
        }
    }

    vector<vector<int>> adj(k + 1);

    for (int i = 1; i < h + 1; i++){
        for (int j = 1; j < w + 1; j++){
            int x = component[i][j];
            for (pair<int, int> t : cardinal){
                int y = component[i + t.first][j + t.second];
                if (x != 0 && y != 0 && x != y){
                    adj[x].pb(y);
                    adj[y].pb(x);
                }
            }
        }
    }

    vector<int> dist(k + 1, -1);

    int ans = 0;

    queue<int> curr;
    curr.push(1);
    dist[1] = 0;

    while(!curr.empty()){
        int comp = curr.front();
        curr.pop();
        
        for (int node : adj[comp]){
            if (dist[node] != -1){
                continue;
            }

            dist[node] = dist[comp] + 1;
            ans = max(ans, dist[node]);

            curr.push(node);
        }
    }

    cout << ans + 1 << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}