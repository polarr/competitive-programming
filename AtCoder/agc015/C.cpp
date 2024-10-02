/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-10-01
 * Contest: AtCoder agc015
 * Problem: C
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

void solve(){
    int n, m, q; cin >> n >> m >> q;
    vector<vector<int>> grid(n + 1, vector<int>(m + 1, 0));
    vector<vector<int>> t = grid;
    vector<vector<int>> tX = grid;
    vector<vector<int>> tY = grid;

    for (int i = 0; i < n; i++){
        string s; cin >> s;
        for (int j = 0; j < m; j++){
            int x = 0;
            if (s[j] == '1'){
                x = 1;
            }
            grid[i + 1][j + 1] = x;
        }
    }

    for (int i = 1; i < n + 1; i++){
        for (int j = 1; j < m + 1; j++){
            t[i][j] = grid[i][j] + t[i - 1][j] + t[i][j - 1] - t[i - 1][j - 1];
            tX[i][j] = (grid[i][j] && grid[i - 1][j]) + tX[i - 1][j] + tX[i][j - 1] - tX[i - 1][j - 1];
            tY[i][j] = (grid[i][j] && grid[i][j - 1]) + tY[i - 1][j] + tY[i][j - 1] - tY[i - 1][j - 1];
        }
    }

    

    for (int i = 0; i < q; i++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        int total = t[x2][y2] - t[x2][y1 - 1] - t[x1 - 1][y2] + t[x1 - 1][y1 - 1];
        x1++;
        int totalX = tX[x2][y2] - tX[x2][y1 - 1] - tX[x1 - 1][y2] + tX[x1 - 1][y1 - 1];
        x1--; y1++;
        int totalY = tY[x2][y2] - tY[x2][y1 - 1] - tY[x1 - 1][y2] + tY[x1 - 1][y1 - 1];

        // cout << total << " " << totalX << " " << totalY << endl;

        cout << total - totalX - totalY << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}