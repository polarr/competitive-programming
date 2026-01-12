/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2026-01-09
 * Contest: IOI 2002
 * Problem: frog
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
    int r, c; cin >> r >> c;

    int n; cin >> n;
    vector<vi> grid(r, vi(c, -1));

    vector<pii> plants(n);

    rep(i, 0, n) {
        int y, x; cin >> y >> x;
        --y; --x;

        plants[i] = {y, x};
        grid[y][x] = i;
    }

    vector<vector<bool>> lines(n, vector<bool>(n, false));

    int ans = 0;

    rep(i, 0, n) {
        rep(j, i + 1, n) {
            if (lines[i][j]) continue;

            auto [y1, x1] = plants[i];
            auto [y2, x2] = plants[j];

            int dy = y2 - y1, dx = x2 - x1;

            int cnt = 1;
            bool bad = false;
            int y = y1 + dy, x = x1 + dx;
            while (0 <= y && y < r && 0 <= x && x < c) {
                int p = grid[y][x];
                if (p == -1) {
                    bad = true;
                    break;
                }

                int q = grid[y - dy][x - dx];

                lines[p][q] = lines[q][p] = true;
                
                cnt++;
                y += dy;
                x += dx;
            }

            y = y1 - dy, x = x1 - dx;
            while (0 <= y && y < r && 0 <= x && x < c) {
                int p = grid[y][x];
                if (p == -1) {
                    bad = true;
                    break;
                }

                int q = grid[y + dy][x + dx];

                lines[p][q] = lines[q][p] = true;
                
                cnt++;
                y -= dy;
                x -= dx;
            }

            if (!bad) {
                ans = max(ans, cnt);
            }
        }
    }

    if (ans < 3) {
        cout << 0 << endl;
        return;
    }

    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}