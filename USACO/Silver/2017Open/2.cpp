/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-02-19
 * Contest: USACO 2017 Open Contest
 * Problem: P2. Cross Country Skiing
**/

#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;

const string iofilename = "ccski";
ifstream fin(iofilename + ".in");
ofstream fout(iofilename + ".out");

vector<vector<ll>> grid;
vector<vector<bool>> waypoint;
vector<vector<bool>> visited;
vector<pair<int, int>> cardinal = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int pts = 0;

void floodfill(int i, int j, ll el){
    if (visited[i][j]){
        return;
    }

    visited[i][j] = true;
    if (waypoint[i][j]){
        pts++;
    }

    for (int x = 0; x < cardinal.size(); x++){
        int ii = i + cardinal[x].first;
        int jj = j + cardinal[x].second;

        if (ii >= 0 && ii < visited.size() && jj >= 0 && jj < visited[0].size() && abs(grid[ii][jj] - grid[i][j]) <= el){
            floodfill(ii, jj, el);
        }
    }
}

// Use fstream (fin, fout) instead of iostream!
void solve(){
    int m, n;
    fin >> m >> n;

    ll minE = LLONG_MAX;
    ll maxE = 0;

    grid = vector<vector<ll>> (m, vector<ll>(n));
    waypoint = vector<vector<bool>> (m, vector<bool>(n, false));

    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            ll el;
            fin >> el;
            grid[i][j] = el;

            minE = min(minE, el);
            maxE = max(maxE, el);
        }
    }

    int wayX = 0;
    int wayY = 0;
    int total = 0;

    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            int x;
            fin >> x;
            if (x == 1){
                waypoint[i][j] = true;
                wayX = j;
                wayY = i;
                total++;
            }
        }
    }

    ll left = 0;
    ll right = maxE - minE;

    while(left < right){
        ll mid = (left + right)/2;
        visited = vector<vector<bool>> (m, vector<bool>(n, false));
        pts = 0;
        floodfill(wayY, wayX, mid);

        if (pts == total){
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    fout << left << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    solve();
    return 0;
}