/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-05-09
 * Contest: CSES Problemset
 * Problem: 1192
**/

#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using pii = pair<int, int>;
#define pb push_back
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

void solve(){
    int n, m; cin >> n >> m;

    vector<vector<bool>> grid(n + 2, vector<bool>(m + 2, false)), visited = grid;
    rep(i, 0, n + 2){
        grid[i][0] = true;
        grid[i][m + 1] = true;
    }

    rep(i, 0, m + 2){
        grid[0][i] = true;
        grid[n + 1][i] = true;
    }

    rep(i, 1, n + 1){
        rep(j, 1, m + 1){
            char x; cin >> x;
            if (x == '#') grid[i][j] = true;
        }
    }

    int c = 0;

    function<void(int, int)> floodfill;
    floodfill = [&](int y, int x){
        if (grid[y][x] || visited[y][x]) return;
        visited[y][x] = true;

        floodfill(y + 1, x);
        floodfill(y - 1, x);
        floodfill(y, x + 1);
        floodfill(y, x - 1);
    };

    rep(i, 1, n + 1){
        rep(j, 1, m + 1){
            if (grid[i][j] || visited[i][j]) continue;

            c++;

            floodfill(i, j);
        }
    }

    cout << c << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}