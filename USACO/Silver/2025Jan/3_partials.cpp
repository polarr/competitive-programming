/**
 * Solution by 1egend (polarity.sh)
 * Date: 2025-01-24
 * Contest: USACO 2025 January Silver
 * Problem: 3
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
    int n; cin >> n;
    vector<vector<int>> grid(n, vector<int>(n, 0)), ans = grid, startGrid = grid;
    rep(i, 0, n){
        rep(j, 0, n){
            cin >> grid[i][j];
            startGrid[i][j] = i + j + 2;
        }
    }

    vector<pair<int, int>> colors(n + 1);
    rep(i, 0, n + 1){
        colors[i + 1] = {i + 2, 2 * n - i};
    }

    vector<int> givenColors(2 * n + 1, 0);
    rep(i, 0, n){
        rep(j, 0, n){
            givenColors[grid[i][j]]++;
        }
    }

    vector<int> per(n);
    for (int i = 0; i < n; i++){
        per[i] = i;
    }

    vector<vector<vector<int>>> possible;

    for (int i = 0; i < pow(2, n); i++){
        vector<bool> found(n + 1, false);
        vector<int> assigned(2 * n + 1, 0);
        for (int k = 1; k < 2 * n + 1; k++){
            int realColor = givenColors[k];
            if (!found[realColor]){
                found[realColor] = true;
                bool toggled = i & (1 << (realColor - 1));

                if (toggled){
                    assigned[k] = colors[realColor].first;
                } else {
                    assigned[k] = colors[realColor].second;
                }

                continue;
            }

            bool toggled = i & (1 << (realColor - 1));

            if (!toggled){
                assigned[k] = colors[realColor].first;
            } else {
                assigned[k] = colors[realColor].second;
            }
        }

        vector<int> per1 = per;
        do {
            vector<int> per2 = per;
            do {
                bool good = true;
                for (int ii = 0; ii < n; ii++){
                    for (int jj = 0; jj < n; jj++){
                        int testColor = assigned[grid[ii][jj]];
                        if (testColor != startGrid[per1[ii]][per2[jj]]){
                            good = false;
                            break;
                        }
                    }
                }

                if (good){
                    vector<vector<int>> potential(n, vector<int>(n));
                    for (int ii = 0; ii < n; ii++){
                        for (int jj = 0; jj < n; jj++){
                            int testColor = assigned[grid[ii][jj]];
                            potential[ii][jj] = testColor;
                        }
                    }

                    possible.pb(potential);
                }
            } while (next_permutation(all(per2)));
        } while(next_permutation(all(per1)));
    }

    sort(all(possible));
    rep(i, 0, n){
        rep(j, 0, n){
            cout << possible[0][i][j] << " ";
        }

        cout << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}