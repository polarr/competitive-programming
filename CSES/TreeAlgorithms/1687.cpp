/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-05-07
 * Contest: CSES Problemset
 * Problem: 1687
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
    int n, q; cin >> n >> q;
    
    int lg = log2(n) + 1;

    vi pow2(lg);
    int num = 1;
    pow2[0] = 1;
    rep(i, 1, lg){
        num *= 2;
        pow2[i] = num;
    }

    vector<vi> jump(n, vi(lg, -1));
    
    vector<vi> adj(n);
    vi par(n, -1);
    rep(i, 1, n){
        int p; cin >> p;
        --p;

        jump[i][0] = p;

        adj[p].pb(i);
    }

    function<int(int, int)> query;
    query = [&](int x, int k){
        if (x <= 0){
            return -1;
        }

        int i = log2(k);
        int d = pow2[i];

        if (d == k){
            return jump[x][i];
        }

        return query(jump[x][i], k - d);
    };

    rep(i, 1, lg){
        rep(j, 0, n){
            int k = jump[j][i - 1];
            if (k == -1) continue;
            jump[j][i] = jump[k][i - 1];
        }
    }

    rep(i, 0, q){
        int x, k; cin >> x >> k;
        --x;

        int ans = query(x, k);
        if (ans == -1){
            cout << -1 << endl;
            continue;
        }

        cout << ans + 1 << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}