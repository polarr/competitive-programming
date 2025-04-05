/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-04-01
 * Contest: 
 * Problem: afd2p5
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
    int n, m; cin >> n >> m;

    int ans = INT_MAX;

    vector<vi> adj(n, vi(n, INT_MAX));

    rep(i, 0, m){
        int a, b; cin >> a >> b;
        int w; cin >> w;

        --a; --b;
        adj[a][b] = min(adj[a][b], w);
        adj[b][a] = min(adj[a][b], w);
    }

    vi a(n);

    rep(i, 0, n){
        a[i] = i;
    }

    do {
        bool good = true;
        int total = 0;
        rep(i, 0, n){
            int w = adj[a[i]][a[(i - 1 + n) % n]];
            if (w == INT_MAX){
                good = false;
                break;
            }

            total += w;
        }

        if (good){
            ans = min(ans, total);
        }
    } while(next_permutation(all(a)));

    if (ans == INT_MAX){
        cout << -1 << endl;
    } else {
        cout << ans << endl;
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