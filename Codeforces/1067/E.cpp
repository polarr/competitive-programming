/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-11-29
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
const int INF = 2e9;

void solve(){
    int n, m; cin >> n >> m;

    int k = n * m;

    int ans = 0;
    vl grid(k);
    auto idx = [&](int i, int j) -> int {
        if (i < 0 || i >= n || j < 0 || j >= m) {
            return -1;
        }

        return i * m + j;
    };
    vector<vi> adj(k);
    auto connect = [&](int i, int j) {
        adj[i].pb(j);
        adj[j].pb(i);
    };
    rep(i, 0, n){
        rep(j, 0, m) {
            int at = idx(i, j);
            cin >> grid[at];

            int l = idx(i, j - 1);
            int r = idx(i, j + 1);
            int u = idx(i - 1, j);
            int d = idx(i + 1, j);
            if (l != -1) connect(at, l);
            if (r != -1) connect(at, r);
            if (u != -1) connect(at, u);
            if (d != -1) connect(at, d);
        }
    }

    vector<bool> power(k, false);
    vector<bool> visited(k);

    function<void(int)> empower, depower;
    empower = [&](int node) {
        if (power[node]) return;
        queue<int> q;
        q.push(node);
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            power[x] = true;
            for (int a : adj[x]) {
                if (power[a]) continue;
                if (grid[a] == grid[node]) {
                    q.push(a);
                }
            }
        }
    };

    depower = [&](int node) {
        if (!power[node]) return;
        queue<int> q;
        q.push(node);
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            power[x] = false;
            for (int a : adj[x]) {
                if (!power[a]) continue;
                if (grid[a] == grid[node]) {
                    q.push(a);
                }
            }
        }
    };

    rep(node, 0, k) {
        if (visited[node]) continue;
        queue<int> q;
        q.push(node);
        vi connected;
        bool pw = true;
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            visited[x] = true;
            connected.pb(x);
            for (int a : adj[x]) {
                if (grid[a] < grid[x]) {
                    pw = false;
                }

                if (visited[a]) continue;

                if (grid[a] == grid[x]) {
                    q.push(a);
                }
            }
        }

        for (int x : connected) {
            power[x] = pw;
        }

        if (pw) ans++;
    }

    cout << ans << endl;

    auto update = [&](int i, int j, ll v) {
        int x = idx(i, j);

        if (power[x]) {
            depower(x);
            power[x] = true;
            grid[x] -= v;
            return;
        }
        
        grid[x] -= v;
        bool isPower = true;
        for (int a : adj[x]) {
            if (grid[a] < grid[x] || (grid[a] == grid[x] && !power[a])) {
                isPower = false;
            }
        }

        if (isPower) {
            int already = 0;
            for (int a : adj[x]) {
                if (grid[a] == grid[x]) {
                    already++;
                    
                }

                if (grid[a] > grid[x]) {
                    if (power[a]) {
                        ans--;
                    }

                    depower(a);
                }
            }
            empower(x);
            return;
        }

        for (int a : adj[x]) {
            if (grid[a] >= grid[x]) {
                if (power[a]) {
                    ans--;
                }

                depower(a);
            }
        }

        depower(x);
    };

    int q; cin >> q;
    rep(qq, 0, q) {
        int i, j; cin >> i >> j;
        --i; --j;
        ll v; cin >> v;
        update(i, j, v);
        cout << ans << '\n';
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