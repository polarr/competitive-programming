/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2026-01-31
 * Contest: 
 * Problem: B
**/

#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define pb push_back
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e15;

void solve(){
    int n; cin >> n;

    ll total = 0;
    vector<vector<pll>> adj(n);
    rep(i, 0, n - 1) {
        int a, b; cin >> a >> b;
        --a; --b;
        ll c; cin >> c;
        total += c * 2;
        adj[a].pb({b, c});
        adj[b].pb({a, c});
    }

    int k = 2 * n - 1;
    vl large(n, 0);
    vl ans(k, 0);
    vector<vl> dp(n, vl(k, -INF)), pre = dp, full = dp;

    auto merge = [&](int x, int node, ll c) {
        vl ndp = dp[node], npre = pre[node], nfull = full[node];
        bool swapped = false;
        if (large[x] < large[node]) {
            swap(large[x], large[node]);
            swap(dp[x], dp[node]);
            swap(pre[x], pre[node]);
            swap(full[x], full[node]);
            swapped = true;
        }

        // just think of c a bridge

        rep(i, 0, k) {
            rep(j, 0, 2 * large[node] - 1) {
                if (i - j - 1 < 0) break;
                bool isEntire = (!swapped && i - j - 2 == 2 * large[x] - 2) || (swapped && j == 2 * large[node] - 2);
                if (i - j - 2 >= 0 && isEntire) nfull[i] = max(nfull[i], full[node][j] + full[x][i - j - 2] + c * 2);
                npre[i] = max(npre[i], nfull[i]);
                if (!swapped) {
                    if (i - j - 2 >= 0 && i - j - 2 == 2 * large[x] - 2) npre[i] = max(npre[i], pre[node][j] + full[x][i - j - 2] + c * 2);
                    npre[i] = max(npre[i], full[node][j] + pre[x][i - j - 1] + c);
                } else {
                    npre[i] = max(npre[i], pre[node][j] + full[x][i - j - 1] + c);
                    if (i - j - 2 >= 0 && j == 2 * large[node] - 2) npre[i] = max(npre[i], full[node][j] + pre[x][i - j - 2] + c * 2);
                }
                ndp[i] = max(ndp[i], npre[i]);
                ndp[i] = max(ndp[i], pre[node][j] + pre[x][i - j - 1] + c);
                if (!swapped) {
                    if (i - j - 2 >= 0 && i - j - 2 == 2 * large[x] - 2) ndp[i] = max(ndp[i], dp[node][j] + full[x][i - j - 2] + c * 2);
                } else {
                    if (i - j - 2 >= 0 && j == 2 * large[node] - 2) ndp[i] = max(ndp[i], full[node][j] + dp[x][i - j - 2] + c * 2);
                }
            }

            ans[i] = max(ans[i], ndp[i]);
        }

        large[node] += large[x];
        dp[node] = ndp;
        pre[node] = npre;
        full[node] = nfull;
    };

    function<void(int, int)> dfs;
    dfs = [&](int node, int par) {
        large[node] = 1;
        dp[node][0] = pre[node][0] = full[node][0] = 0;
        for (auto [x, c] : adj[node]) {
            if (x == par) continue;
            dfs(x, node);
            merge(x, node, c);
        }
    };

    dfs(0, -1);

    // cout << full[1][2] << endl;

    rep(i, 0, k) {
        cout << total - ans[i] << ' ';
    }

    cout << '\n';
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