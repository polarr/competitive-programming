/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2026-02-20
 * Contest: 
 * Problem: I
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
ll MOD = 1e9 + 7;

/** 
 * DATASTRUCTURE: 2D Prefix Sum
 * PURPOSE: Fast range sum queries on a matrix
 * CONSTRAINT: Must input a non-degenerate 2 dimensional matrix
 * TIME: O(nm) to precompute, O(1) to query
*/
template <class T> class Prefix2D {
    private:
        vector<vector<T>> matrix;
    public:
        Prefix2D(vector<vector<T>> &grid){
            matrix = vector<vector<T>>(grid.size() + 1, vector<T>(grid[0].size() + 1, 0));

            for (int i = 0; i < grid.size(); i++){
                for (int j = 0; j < grid[0].size(); j++){
                    matrix[i + 1][j + 1] = grid[i][j] + matrix[i][j + 1] + matrix[i + 1][j] - matrix[i][j] + MOD;
                    matrix[i + 1][j + 1] %= MOD;
                }
            }
        }

        /**
         * CONSTRAINT: 1 <= y1 <= y2 <= height, 1 <= x1 <= x2 <= width
         * RETURN: sum of submatrix with top-left corner x1, y1 and bottom right corner x2, y2 */
        T query(int x1, int y1, int x2, int y2){
            --x1; --y1;
            return (matrix[y2][x2] + matrix[y1][x1] + MOD + MOD - matrix[y2][x1] - matrix[y1][x2]) % MOD;
        }
};

void solve(){
    int n, k; cin >> n >> k;
    cin >> MOD;

    if (n == 1) {
        cout << 1 << endl;
        return;
    }

    vector<vector<vl>> dp(n + 1, vector<vl>(n, vl(k + 1, 0)));

    rep(i, 0, n) {
        dp[1][i][1]++;
    }

    Prefix2D<ll> pre(dp[1]);

    rep(j, 2, n + 1) {
        int rem = n - j + 1;
        rep(i, 0, rem) {
            rep(l, 2, k + 1) {
                if (l == 2) {
                    dp[j][i][l] += pre.query(1, rem - i + 1, k + 1, rem + 1);
                    dp[j][i][l] %= MOD;
                }

                dp[j][i][l] += pre.query(l, 1, l, i + 1);
                dp[j][i][l] %= MOD;
            }
        }

        pre = Prefix2D<ll>(dp[j]);
    }

    ll ans = 0;
    rep(i, 0, n) {
        rep(j, 0, k + 1) {
            ans += dp[n][i][j];
            ans %= MOD;
        }
    }

    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}