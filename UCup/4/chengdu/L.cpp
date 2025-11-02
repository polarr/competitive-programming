#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
#define pb push_back
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define sz(x) (int)(x).size()

void solve() {
    int n;
    cin >> n;

    vi a(n), b(n);
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n) cin >> b[i];

    vector<vi> adj(n);
    rep(i, 0, n - 1){
        int x, y; cin >> x >> y;
        --x; --y;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    vector<map<int, int>> mp(n);
    vi cnt(n, 0);

    vi sum(n, 0), ans(n, 0);
    function<void(int, int)> dfs, merge;

    merge = [&](int x, int y){
        if (sz(mp[x]) > sz(mp[y])){
            swap(mp[x], mp[y]);
            swap(sum[x], sum[y]);
            swap(cnt[x], cnt[y]);
        }

        cnt[y] += cnt[x];

        for (auto &[p, q] : mp[x]){
            sum[y] -= abs(mp[y][p]);
            mp[y][p] += q;
            sum[y] += abs(mp[y][p]); 
        }
    };

    dfs = [&](int node, int par){
        if (a[node] == 0){
            cnt[node]++;
        } else {
            mp[node][a[node]]++;
            sum[node]++;
        }

        if (b[node] == 0){
            cnt[node]++;
        } else {
            mp[node][b[node]]--;
            if (a[node] == b[node]){
                sum[node] = 0;
            } else {
                sum[node]++;
            }
        }

        for (int x : adj[node]){
            if (x == par) continue;
            dfs(x, node);
            merge(x, node);
        }

        if (sum[node] - cnt[node] <= 0){
            ans[node] = 1;
        }
    };

    dfs(0, -1);

    rep(i, 0, n){
        cout << ans[i];
    }

    cout << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int test;
    cin >> test;
    while (test--) {
        solve();
    }
}
