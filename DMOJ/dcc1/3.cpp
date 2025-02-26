/**
 * Solution by 1egend (polarity.sh)
 * Date: 2025-02-21
 * Contest: DMOJ dcc1
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

/** 
 * DATASTRUCTURE: 2D Prefix Sum
 * PURPOSE: Fast queries on a matrix
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
                    matrix[i + 1][j + 1] = grid[i][j] + matrix[i][j + 1] + matrix[i + 1][j] - matrix[i][j];
                }
            }
        }

        /**
         * CONSTRAINT: 1 <= y1 <= y2 <= height, 1 <= x1 <= x2 <= width
         * RETURN: sum of submatrix with top-left corner x1, y1 and bottom right corner x2, y2 */
        T query(int x1, int y1, int x2, int y2){
            --x1; --y1;
            return matrix[y2][x2] + matrix[y1][x1] - matrix[y2][x1] - matrix[y1][x2];
        }
};

void solve(){
    int n, m; cin >> n >> m;
    vector<vl> grid(n, vl(m));
    rep(i, 0, n){
        rep(j, 0, m){
            cin >> grid[i][j];
        }
    }

    Prefix2D<ll> rq(grid);

    ll ans = 0;

    for (int x1 = 1; x1 <= m - 1; x1++){
        for (int x2 = x1 + 1; x2 <= m; x2 += 2){
            int mid = (x1 + x2)/2;
            map<ll, int> first;
            first[0] = 0;
            ll prefix = 0;
            rep(y, 1, n + 1){
                prefix += rq.query(x1, y, mid, y) - rq.query(mid + 1, y, x2, y);
                if (first.contains(prefix)){
                    // cout << x1 << " " << x2 << " " << y << " " << first[prefix] << " " << prefix << endl;
                    ans = max(ans, (ll)(x2 - x1 + 1) * (ll)(y - first[prefix]));
                } else {
                    first[prefix] = y;
                }
            }
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