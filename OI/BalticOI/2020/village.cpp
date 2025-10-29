/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-10-28
 * Contest: Baltic OI 2020
 * Problem: village
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

// only solves the maximum case
void solve(){
    int n; cin >> n;
    vector<vi> adj(n);
    rep(i, 0, n - 1){
        int a, b; cin >> a >> b;
        --a; --b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    
    vi subtree(n, 1);
    vi depth(n, 0);
    function<void(int, int)> dfs1, dfs2;
    dfs1 = [&](int node, int par){
        if (par != -1) {
            depth[node] = depth[par] + 1;
        }
        for (int x : adj[node]){
            if (x == par) continue;
            dfs1(x, node);
            subtree[node] += subtree[x];
        }
    };

    dfs1(0, -1);

    int centroid = 0;
    dfs2 = [&](int node, int par){
        int go = -1;
        for (int x : adj[node]){
            if (x == par) continue;
            if (subtree[x] > n/2){
                go = x;
                break;
            }
        }

        if (go == -1){
            centroid = node;
            return;
        }

        dfs2(go, node);
    };

    dfs2(0, -1);

    subtree = vi(n, 1);
    depth = vi(n, 0);
    dfs1(centroid, -1);

    ll ans = 0;
    rep(i, 0, n){
        ans += 2LL * depth[i];
    }

    cout << ans << endl;

    vi assign(n);
    vector<vi> groups;
    if (n % 2 == 0){
        groups.pb({centroid});
    }
    function<void(int, int, vi&)> dfs3;
    dfs3 = [&](int node, int par, vi& group){
        group.pb(node);
        for (int x : adj[node]){
            if (x == par) continue;
            dfs3(x, node, group);
        }
    };

    for (int x : adj[centroid]){
        vi group;
        dfs3(x, centroid, group);
        groups.pb(group);
    }

    priority_queue<pii> pq;

    rep(i, 0, sz(groups)){
        pq.push({sz(groups[i]), i});
    }

    bool flag = n % 2 == 1;

    while (!pq.empty()){
        assert(pq.size() > 1);
        auto [big, i] = pq.top();
        pq.pop();
        auto [small, j] = pq.top();
        pq.pop();

        int a = groups[i].back(), b = groups[j].back();
        if (flag){
            assign[a] = centroid;
            assign[centroid] = b;
            assign[b] = a;
            flag = false;
        } else {
            assign[a] = b;
            assign[b] = a;
        }

        groups[i].pop_back();
        groups[j].pop_back();

        if (big > 1) pq.push({big - 1, i});
        if (small > 1) pq.push({small - 1, j});
    }

    rep(i, 0, n){
        cout << assign[i] + 1 << " ";
    }

    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}