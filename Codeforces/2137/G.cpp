/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-09-12
 * Contest: Codeforces 2137
 * Problem: G
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

pii& operator+=(pii& a, const pii& b) {
    a.first += b.first;
    a.second += b.second;
    return a;
}

pii& operator-=(pii& a, const pii& b) {
    a.first -= b.first;
    a.second -= b.second;
    return a;
}

void solve(){
    int n, m, q; cin >> n >> m >> q;
    vector<vi> radj(n);
    vi deg(n, 0);
    vector<pii> sums(n, {0, 0});
    rep(i, 0, m){
        int a, b; cin >> a >> b;
        --a; --b;
        deg[a]++;
        sums[a].first++;
        radj[b].pb(a);
    }

    vector<pii> state(n, {1, 0});
    vector<bool> red(n, false);
    function<void(int)> dfs;
    dfs = [&](int node){
        if (red[node]) return;
        int k = deg[node];
        pii ns = {sums[node].second < k ? 1 : 0, sums[node].first < k ? 1 : 0};
        if (ns.first != state[node].first || ns.second != state[node].second){
            for (int x : radj[node]){
                sums[x] += ns;
                sums[x] -= state[node];
            }

            state[node] = ns;
            for (int x : radj[node]){
                dfs(x);
            }
        }
    };

    rep(i, 0, q){
        int x, node; cin >> x >> node;
        --node;
        if (x == 2){
            cout << (state[node].first ? "YES" : "NO") << endl;
            continue;
        }

        red[node] = true;
        pii ns = {0, 1};
        if (ns.first != state[node].first || ns.second != state[node].second){
            for (int x : radj[node]){
                sums[x] += ns;
                sums[x] -= state[node];
            }

            state[node] = ns;
            for (int x : radj[node]){
                dfs(x);
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