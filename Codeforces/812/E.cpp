/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2026-01-11
 * Contest: 
 * Problem: E
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

    vi apples(n);
    rep(i, 0, n) cin >> apples[i];
    vector<vi> children(n);
    rep(i, 1, n) {
        int p; cin >> p;
        --p;
        children[p].pb(i);
    }

    vi depth(n, 0);
    int leaf;

    function<void(int, int)> dfs;
    dfs = [&](int x, int par) {
        if (x != 0) depth[x] = 1 - depth[par];
        if (children[x].empty()) {
            leaf = x;
        }
        for (int node : children[x]) {
            dfs(node, x);
        }
    };

    dfs(0, -1);

    map<int, int> cnt;

    ll good = 0, bad = 0;
    int z = 0;
    rep(i, 0, n) {
        if (depth[i] == depth[leaf]) {
            good++;
            z ^= apples[i];
        } else {
            bad++;
            cnt[apples[i]]++;
        }
    }

    ll ans = 0;
    if (z == 0) {
        ans += (good * (good - 1))/2;
        ans += (bad * (bad - 1))/2;
    }

    rep(i, 0, n) {
        if (depth[i] != depth[leaf]) continue;
        int k = z ^ apples[i];
        ans += cnt[k];
    }

    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}