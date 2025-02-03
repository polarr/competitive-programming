/**
 * Solution by 1egend (polarity.sh)
 * Date: 2025-02-01
 * Contest: Codeforces 2056
 * Problem: B
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
    vector<vi> adj(n, vi(n));
    rep(i, 0, n){
        string s; cin >> s;
        rep(j, 0, n){
            adj[i][j] = s[j] - '0';
        }
    }

    vi ans(n, -1);

    for (int i = n - 1; i >= 0; i--){
        int deg = 0;
        rep(j, 0, i){
            if (adj[i][j] == 1){
                deg++;
            }
        }

        int c = 0;
        rep(j, 0, n){
            if (ans[j] != -1){
                continue;
            }

            if (c == deg){
                ans[j] = i;
            }
            c++;
        }
    }

    rep(i, 0, n){
        cout << ans[i] + 1 << " ";
    }

    cout << endl;
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