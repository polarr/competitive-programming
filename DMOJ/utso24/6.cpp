/**
 * Solution by 1egend (polarity.sh)
 * Date: 2025-01-03
 * Contest: DMOJ utso24
 * Problem: 6
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

void solve(){
    int n, qr; cin >> n >> qr;
    
    vector<vector<pair<int, int>>> adj(n, vector<pair<int, int>>(n));

    vector<int> students(n, 0);

    for (int i = 0; i < n - 1; i++){
        int a, b; cin >> a >> b;
        --a; --b;
        adj[a].pb({b, 1});
        adj[b].pb({a, 1});
    }

    for (int i = 0; i < qr; i++){
        char c; int x, k; cin >> c >> x >> k;
        if (c == 'U'){
            --x;
            students[x] += k;
            continue;
        }

        --x; --k;
        adj[x].pb({k, 1});
        adj[k].pb({x, 1});

        vector<int> d(n, INT_MAX);
        d[0] = 0;
        deque<int> q;
        q.push_front(0);
        while (!q.empty()) {
            int v = q.front();
            q.pop_front();
            for (auto edge : adj[v]) {
                int u = edge.first;
                int w = edge.second;
                if (d[v] + w < d[u]) {
                    d[u] = d[v] + w;
                    if (w == 1)
                        q.push_back(u);
                    else
                        q.push_front(u);
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++){
            ans += students[i] * d[i];
        }

        cout << ans << endl;

        adj[x].pop_back();
        adj[k].pop_back();
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}