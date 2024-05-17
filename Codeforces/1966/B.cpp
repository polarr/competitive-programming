/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-04-27
 * Contest: Codeforces Round 1966
 * Problem: B.
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

void solve(){
    int n, m; cin >> n >> m;
    vector<vector<bool>> grid(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            char x; cin >> x;
            if (x == 'B'){
                grid[i][j] = true;
            }
        }
    }

    int ans = true;

    if (grid[0][0] != grid[n - 1][m - 1] && grid[0][m - 1] != grid[n - 1][0]){
        // possible no
        ans = false;
        if (grid[0][0] == grid[0][m - 1]){
            // hor equal
            for (int i = 0; i < m - 1; i++){
                if (grid[0][i] != grid[0][i + 1] || grid[n - 1][i] != grid[n - 1][i + 1]){
                    ans = true;
                    break;
                }
            }
        } else {
            // vert equal
            for (int i = 0; i < n - 1; i++){
                if (grid[i][0] != grid[i + 1][0] || grid[i][m - 1] != grid[i + 1][m - 1]){
                    ans = true;
                    break;
                }
            }
        }
    }

    cout << (ans ? "YES":"NO") << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for (int t = 1; t <= tc; ++t){
        // cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}