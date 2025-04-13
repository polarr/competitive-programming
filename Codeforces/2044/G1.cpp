/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-04-12
 * Contest: Codeforces 2044
 * Problem: G1
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

    vi to(n);
    rep(i, 0, n){
        cin >> to[i];
        --to[i];
    }

    vector<bool> visited(n, false);
    vector<int> dist(n, -1);

    int ans = 0;
    rep(i, 0, n){
        if (visited[i]) continue;

        int x = i;
        vi path;
        while (!visited[x]){
            visited[x] = true;
            path.pb(x);
            x = to[x];
        }

        int cycle = -1;

        rep(j, 0, path.size()){
            int visit = path[j];
            if (x == visit){
                // cycle starts
                cycle = j;
            }

            if (cycle != -1){
                dist[visit] = 0;
            }
        }

        if (cycle == -1){
            rep(j, 0, path.size()){
                int el = path.size() - 1 - j;
                dist[path[el]] = dist[x] + j + 1;
            }
        } else {
            rep(j, 0, cycle){
                int el = cycle - j - 1;
                dist[path[el]] = j + 1;
            }
        }
    }

    rep(i, 0, n){
        ans = max(ans, dist[i]);
    }

    cout << ans + 2 << endl;
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