/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-10-07
 * Contest: IOI 2011
 * Problem: race
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

const int MAX_N = 2e5 + 1;
const ll MOD = 1e9 + 7;

vector<vector<pair<int, ll>>> adj(MAX_N);
vector<map<ll, int>> mp(MAX_N);
vl add(MAX_N, 0);
int ans = INT_MAX;
int n; ll k;

void merge(int a, int b, int depth){
    if (sz(mp[b]) > sz(mp[a])){
        swap(mp[a], mp[b]);
        swap(add[a], add[b]);
    }

    ll tot = k - add[a] - add[b];

    for (auto &[dist, d] : mp[b]){
        if (mp[a].contains(tot - dist)){
            ans = min(ans, d + mp[a][tot - dist] - 2 * depth);
        }
    }

    for (auto &[dist, d] : mp[b]){
        ll cd = dist + add[b] - add[a];
        if (!mp[a].contains(cd)){
            mp[a][cd] = d;
        } else {
            mp[a][cd] = min(mp[a][cd], d);
        }
    }
}

void dfs(int node, int par, int depth){
    mp[node][0] = depth;
    for (auto &[x, l] : adj[node]){
        if (x == par) continue;
        dfs(x, node, depth + 1);
        add[x] += l;
        merge(node, x, depth);
    }
}

void solve(){
    cin >> n >> k;
    rep(i, 0, n - 1){
        int a, b; cin >> a >> b;
        ll len; cin >> len;
        adj[a].pb({b, len});
        adj[b].pb({a, len});
    }

    dfs(0, -1, 0);
    if (ans == INT_MAX){
        cout << -1 << endl;
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