/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2026-02-07
 * Contest: 
 * Problem: K
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

void first(){
    int n; cin >> n;
    vector<vi> adj(n);

    rep(i, 0, n - 1) {
        int a, b; cin >> a >> b;
        --a; --b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    vi ans(n, 0);
    vi best(n, -1);
    vector<array<int, 2>> dp(n, {0, 0});
    function<void(int, int)> dfs;
    dfs = [&](int node, int par) {
        int diff = -1;
        int sum = 0;
        for (int x : adj[node]) {
            if (x == par) continue;
            dfs(x, node);
            sum += dp[x][0];
            if (dp[x][1] - dp[x][0] > diff) {
                best[node] = x;
                diff = dp[x][1] - dp[x][0];
            }
        }

        dp[node][1] = sum;
        dp[node][0] = max(sum, sum + diff + 1);
    };

    dfs(0, -1);

    function<void(int, int, int)> dfs2;
    dfs2 = [&](int node, int par, int must) {
        int dont = -1;
        if (must == 0 && dp[node][1] != dp[node][0]) {
            dont = best[node];
        }

        for (int x : adj[node]) {
            if (x == par) continue;
            if (x != dont) {
                ans[x] = 1 - ans[node];
            } else {
                ans[x] = ans[node];
            }
            dfs2(x, node, x == dont ? 1 : 0);
        }
    };

    dfs2(0, -1, 0);
    string s = "";
    rep(i, 1, n) {
        if (ans[i] == 0) {
            s += "0";
        } else {
            s += "1";
        }
    }

    cout << s << endl;
}

void second(){
    int n; cin >> n;
    string ss; cin >> ss;
    string s = "0" + ss;
    rep(i, 0, n - 1) {
        int a, b; cin >> a >> b;
        --a; --b;
        if (s[a] == s[b]) {
            cout << "take" << endl;
        } else {
            cout << "ignore" << endl;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string cs; cin >> cs;
    if (cs == "prepare") {
        first();
    } else {
        second();
    }
    return 0;
}