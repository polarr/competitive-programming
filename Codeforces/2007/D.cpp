/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-05-10
 * Contest: Codeforces 2007
 * Problem: D
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

    vector<vi> adj(n);
    rep(i, 0, n - 1){
        int a, b; cin >> a >> b;
        --a; --b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    vector<bool> leaf(n, false);

    function<void(int, int)> dfs;
    dfs = [&](int x, int par){
        bool isLeaf = true;
        for (int node : adj[x]){
            if (node == par) continue;
            isLeaf = false;
            dfs(node, x);
        }

        leaf[x] = isLeaf;
    };

    dfs(0, -1);

    string s; cin >> s;

    int zero = 0;
    int one = 0;
    int unknown = 0;
    int par = 0;
    rep(i, 0, n){
        if (!leaf[i] && s[i] == '?' && i != 0) par++;
        if (!leaf[i]) continue;
        if (s[i] == '0'){
            zero++;
        } else if (s[i] == '1'){
            one++;
        } else {
            unknown++;
        }
    }

    if (s[0] == '0') {
        cout << one + (unknown + 1)/2 << endl;
        return;
    }
    if (s[0] == '1') {
        cout << zero + (unknown + 1)/2 << endl;
        return;
    }

    int ans = max(one, zero) + unknown/2;
    if (par % 2 == 1){
        ans = max(ans, min(one, zero) + (unknown + 1)/2);
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