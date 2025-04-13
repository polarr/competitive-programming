/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-04-12
 * Contest: Codeforces 2044
 * Problem: F
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

void solve(){
    int n, m, q; cin >> n >> m >> q;
    
    vl a(n), b(m);
    ll asum = 0, bsum = 0;

    rep(i, 0, n){
        cin >> a[i];
        asum += a[i];
    }

    rep(i, 0, m){
        cin >> b[i];
        bsum += b[i];
    }

    set<ll> aset, anset, bset, bnset;
    vector<bool> can(2 * MAX_N + 10, false);

    rep(i, 0, n){
        ll adj = asum - a[i];
        if (abs(adj) < MAX_N){
            if (adj >= 0){
                aset.insert(adj);
            } else {
                anset.insert(abs(adj));
            }
        }
    }

    rep(i, 0, m){
        ll adj = bsum - b[i];
        if (abs(adj) < MAX_N){
            if (adj >= 0){
                bset.insert(adj);
            } else {
                bnset.insert(abs(adj));
            }
        }
    }

    for (ll r : aset){
        for (ll s : bset){
            if (r * s >= MAX_N){
                break;
            }

            can[r * s + MAX_N] = true;
        }
    }

    for (ll r : aset){
        for (ll s : bnset){
            if (r * s >= MAX_N){
                break;
            }

            can[-r * s + MAX_N] = true;
        }
    }

    for (ll r : anset){
        for (ll s: bnset){
            if (r * s >= MAX_N){
                break;
            }

            can[r * s + MAX_N] = true;
        }
    }

    for (ll r : anset){
        for (ll s : bset){
            if (r * s >= MAX_N){
                break;
            }

            can[-r * s + MAX_N] = true;
        }
    }

    rep(i, 0, q){
        ll x; cin >> x;
        if (can[x + MAX_N]){
            cout << "YES" << endl;
            continue;
        }

        cout << "NO" << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}