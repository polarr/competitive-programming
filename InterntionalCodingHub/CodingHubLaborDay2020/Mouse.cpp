/** Code by 1egend **/
#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;

int md = 1000000007;
/** Recursive approach time limit exceeded :(
int getPaths(vector<vector<int>> grid, int x, int y){
    if (grid[x][y] == 0){
        return 0;
    }
    if (x == 0 && y == 0){
        return 1;
    }
    int a = x > 0 ? (getPaths(grid, x - 1, y) % m): 0;
    int b = y > 0 ? (getPaths(grid, x, y - 1) % m): 0;
    return (a + b) % m;
}
**/
/**
    for (int i = 0; i < grid.size(); i++){
        for (int x = 0; x < grid[i].size(); x++){
            cout << grid[i][x] << " ";
        }
        cout << endl;
    }
**/
int main(){
    int n, m ,t;
    cin >> n >> m >> t;
    vector <vector <ull>> grid(n);
    for (int i = 0; i < n; ++i){
        grid[i].resize(m);
        fill(grid[i].begin(), grid[i].end(), 1);
    }
    for (int i = 0; i < t; ++i){
        int x, y;
        cin >> x >> y;
        grid[x - 1][y - 1] = 0;
        if (x == 1){
            for (int i = y; i < m; ++i){
                grid[0][i] = 0;
            }
        }

        if (y == 1){
            for (int i = x; i < n; ++i){
                grid[i][0] = 0;
            }
        }
    }
    for (int i = 1; i < max<int>(n, m); ++i){
        if (n > i){
            for (int a = 1; a < min<int>(m, i); ++a){
                if (grid[i][a] != 0){
                    grid[i][a] = (grid[i - 1][a] + grid[i][a - 1]) % md;
                }
            }
        }
        if (m > i){
            for (int a = 1; a < min<int>(n, i); ++a){
                if (grid[a][i] != 0){
                    grid[a][i] = (grid[a][i - 1] + grid[a - 1][i]) % md;
                }
            }
        }
        if (n > i && m > i && grid[i][i] != 0){
            grid[i][i] = (grid[i - 1][i] + grid[i][i - 1]) % md;
        }
    }
    cout << grid[n - 1][m - 1];
    //cout << getPaths(grid, n - 1, m - 1);
    return 0;
}
