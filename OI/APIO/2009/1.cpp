/**
 * Solution by 1egend (polarity.sh)
 * Date: 2025-01-15
 * Contest: APIO 2009
 * Problem: 1 - Digging for Oil
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

void solve(){
    int m, n, k; cin >> m >> n >> k;
    vector<vector<int>> grid(m, vector<int>(n));
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            cin >> grid[i][j];
        }
    }

    vector<vector<int>> r(m + 1, vector<int>(n + 1, 0)), c(n + 1, vector<int>(m + 1, 0));

    vector<vector<int>> arr(m - k + 1, vector<int>(n - k + 1));

    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            r[i][j + 1] = r[i][j] + grid[i][j];
            c[j][i + 1] = c[j][i] + grid[i][j];
            if (i < k && j < k){
                arr[0][0] += grid[i][j];
            }
        }
    }
    for (int i = k - 1; i < m; i++){
        for (int j = k - 1; k < n; j++){
            if (j == k - 1){
                if (i != k - 1){
                    arr[i - k + 1][j - k + 1] = arr[i - k][j - k + 1] - (r[i - k + 1][j + 1] - r[i - k + 1][j - k]) + (r[i + 1][j + 1] - r[i + 1][j - k]);
                }
                continue;
            }

            arr[i - k + 1][j - k + 1] = arr[i - k][j - k + 1] - (c[j - k + 1][i + 1] - c[j - k + 1][i - k]) + (c[j + 1][i + 1] - c[j + 1][i - k]);
        }
    }

    // Absolutely insane implementation amount... just do dp max sums from each corner and brute force check the cases
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}