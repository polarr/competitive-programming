/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-05-28
 * Contest: Codeforces 1843
 * Problem: F2
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
    int lg = log2(n + 1) + 1;
    int m = 0;

    vi depth(n + 1, 0);
    vi val(n + 1, 1);

    // 0 vertex, 1 sum, 2 all min, 3 all max, 4 pref min, 5 pref max, 6 suff min, 7 suff max
    vector<vector<array<int, 8>>> jump(n + 1, vector<array<int, 8>>(lg, {-1, 0, 0, 0, 0, 0, 0, 0}));

    auto combine = [&](array<int, 8> &jp1, array<int, 8> &jp2){
        int mid = val[jp1[0]];
        return array<int, 8>{jp2[0], jp1[1] + jp2[1] - mid, 
            min({jp1[2], jp2[2], jp1[6] + jp2[4] - mid}),
            max({jp1[3], jp2[3], jp1[7] + jp2[5] - mid}),
            min(jp1[4], jp1[1] + jp2[4] - mid),
            max(jp1[5], jp1[1] + jp2[5] - mid),
            min(jp2[6], jp2[1] + jp1[6] - mid),
            max(jp2[7], jp2[1] + jp1[7] - mid)
        };
    };

    rep(i, 0, n){
        char c; cin >> c;
        if (c == '+'){
            int v, x; cin >> v >> x;
            --v;

            m++;
            depth[m] = depth[v] + 1;
            val[m] = x;
            int y = val[v];

            jump[m][0] = {v, x + y, min({x, y, x + y}), max({x, y, x + y}), min(x, x + y), max(x, x + y),min(y, y + x), max(y, y + x)};
            rep(j, 1, lg){
                array<int, 8> jp1 = jump[m][j - 1];
                if (jp1[0] == -1) continue;
                array<int, 8> jp2 = jump[jp1[0]][j - 1];
                if (jp2[0] == -1) continue;
                jump[m][j] = combine(jp1, jp2);
            }
        } else {
            int u, v, k; cin >> u >> v >> k;
            --u; --v;
            if (k == 0){
                cout << "YES" << endl;
                continue;
            }

            if (depth[u] > depth[v]){
                swap(u, v);
            }

            int dd = depth[v] - depth[u];
            int at1 = u;
            int at2 = v;
            rep(j, 0, lg){
                if (dd & (1 << j)){
                    at2 = jump[at2][j][0];
                }
            }

            for (int j = lg - 1; j >= 0; j--){
                if (jump[at1][j][0] != jump[at2][j][0]){
                    at1 = jump[at1][j][0];
                    at2 = jump[at2][j][0];
                }
            }

            int l = (u == at2 ? u : jump[at1][0][0]);
            int d1 = depth[u] - depth[l], d2 = depth[v] - depth[l];
            array<int, 8> ans1 = {u, val[u], val[u], val[u], val[u], val[u], val[u], val[u]}, ans2 = {v, val[v], val[v], val[v], val[v], val[v], val[v], val[v]};
            at1 = u;
            at2 = v;
            rep(j, 0, lg){
                if (d1 & (1 << j)){
                    ans1 = combine(ans1, jump[at1][j]);
                    at1 = jump[at1][j][0];
                }

                if (d2 & (1 << j)){
                    ans2 = combine(ans2, jump[at2][j]);
                    at2 = jump[at2][j][0];
                }
            }

            int mn = min({ans1[2], ans2[2], ans1[6] + ans2[6] - val[l]});
            int mx = max({ans1[3], ans2[3], ans1[7] + ans2[7] - val[l]});
            if (mn <= k && k <= mx){
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }
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