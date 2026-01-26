/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2026-01-25
 * Contest: Codeforces 2193
 * Problem: H
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

    vi vals(n);
    rep(i, 0, n) {
        int a; cin >> a;
        vals[i] = a % 2;
    }

    vector<vi> adj(n);
    rep(i, 0, n - 1) {
        int a, b; cin >> a >> b;
        --a; --b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    bool canAns = true;
    vi classify(n, -1);
    vector<vi> zeroWant(n);
    vi classes;
    vi leaders;
    function<void(int, int)> dfs1;
    dfs1 = [&](int node, int par) {
        if (vals[node] == 1) {
            if (par == -1 || vals[par] == 0) {
                classes.pb(node);
                leaders.pb(node);
            }

            classify[node] = leaders.back();
        } else {
            vi ones;
            for (int x : adj[node]) {
                if (vals[x] == 1) {
                    ones.pb(x);
                }
            }

            if (sz(ones) == 0) {
                canAns = false;
            }

            zeroWant[node] = ones;
        }

        for (int x : adj[node]) {
            if (x == par) continue;
            dfs1(x, node);
        }

        if (sz(leaders) != 0 && leaders.back() == node) {
            leaders.pop_back();
        }
    };

    dfs1(0, -1);
    if (!canAns) {
        cout << "NO\n";
        return;
    }

    vi ans;
    vector<vi> helpZero(n);
    rep(i, 0, n) {
        if (sz(zeroWant[i]) % 2 == 1) {
            ans.pb(i);
            continue;
        }
        
        for (int x : zeroWant[i]) {
            helpZero[classify[x]].pb(i);
        }
    }

    vector<bool> placed(n, false);
    vi currback;
    function<int(int, int, int)> dfs2;
    dfs2 = [&](int node, int par, int c) {
        int a = 0;
        for (int x : adj[node]) {
            if (x == par || classify[x] != c) continue;
            a += dfs2(x, node, c);
        }

        if (node != c) {
            a++;
        }

        if (a % 2 == 0) {
            ans.pb(node);
            return 0;
        }

        if (node == c) {
            canAns = false;
        }
        currback.pb(node);
        return 1;
    };

    rep(i, 0, sz(classes)) {
        int x = classes[i];
        currback = {};
        dfs2(x, -1, x);
        if (!canAns) {
            cout << "NO\n";
            return;
        }

        reverse(all(currback));
        for (int j : currback) {
            ans.pb(j);
        }

        for (int j : helpZero[x]) {
            if (placed[j]) continue;
            placed[j] = true;
            ans.pb(j);
        }
    }

    cout << "YES\n";
    rep(i, 0, sz(ans)) {
        cout << ans[i] + 1 << " ";
    }
    cout << "\n";
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