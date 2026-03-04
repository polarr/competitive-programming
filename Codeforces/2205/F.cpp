/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2026-03-03
 * Contest: 
 * Problem: F
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

// this is so trivial??? but implementation hell

vector<pii> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void solve(){
    int n, m; cin >> n >> m;

    int nn = n - 1, mm = m - 1;

    vector<vl> wh(nn, vl(m));
    vector<vl> wv(n, vl(mm));

    vector<vector<bool>> ah(nn, vector<bool>(m));
    vector<vector<bool>> av(n, vector<bool>(mm));

    rep(i, 0, nn) {
        rep(j, 0, m) {
            cin >> wh[i][j];
        }
    }

    rep(i, 0, n) {
        rep(j, 0, mm) {
            cin >> wv[i][j];
        }
    }

    rep(i, 0, nn) {
        rep(j, 0, m) {
            char x; cin >> x;
            ah[i][j] = x - '0';
        }
    }

    rep(i, 0, n) {
        rep(j, 0, mm) {
            char x; cin >> x;
            av[i][j] = x - '0';
        }
    }

    vector<vector<bool>> visited(nn, vector<bool>(mm, false));

    auto bounded = [&](pii loc) -> bool {
        return loc.first >= 0 && loc.first < nn && loc.second >= 0 && loc.second < mm;
    };

    function<void(pii, vector<pii>&, vector<pii>&, bool&)> floodfill;
    floodfill = [&](pii loc, vector<pii>& h, vector<pii>& v, bool& bad) {
        auto [y, x] = loc;

        if (visited[y][x]) return;
        visited[y][x] = true;

        rep(i, 0, 4) {
            pii d = dir[i];
            if (i == 0 && av[y + 1][x]) {
                v.pb({x, y + 1});
                continue;
            }

            if (i == 1 && av[y][x]) {
                v.pb({x, y});
                continue;
            }

            if (i == 2 && ah[y][x + 1]) {
                h.pb({y, x + 1});
                continue;
            }

            if (i == 3 && ah[y][x]) {
                h.pb({y, x});
                continue;
            }

            pii nd = {loc.first + d.first, loc.second + d.second};
            if (!bounded(nd)) {
                bad = true;
                continue;
            }

            floodfill(nd, h, v, bad);
        }
    };

    ll ans = 0;

    rep(i, 0, nn) {
        rep(j, 0, mm) {
            if (visited[i][j]) continue;
            vector<pii> h, v;
            bool bad = false;
            floodfill({i, j}, h, v, bad);

            if (bad) continue;

            sort(all(h));
            sort(all(v));

            ll shape = 0;
            int curr = 0;
            rep(k, 0, sz(h)) {
                auto [y, x] = h[k];
                if (k == 0 || h[k].first != h[k - 1].first) {
                    curr = 0;
                }

                curr++;
                if (curr % 2 == 1) {
                    shape += wh[y][x];
                } else {
                    shape -= wh[y][x];
                }
            }

            curr = 0;
            rep(k, 0, sz(v)) {
                auto [x, y] = v[k];
                if (k == 0 || v[k].first != v[k - 1].first) {
                    curr = 0;
                }

                curr++;
                if (curr % 2 == 1) {
                    shape += wv[y][x];
                } else {
                    shape -= wv[y][x];
                }
            }

            if (shape > 0) {
                ans += shape;
            }

            // cout << i << " " << j << " " << shape << endl;
        }
    }

    cout << ans << endl;
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