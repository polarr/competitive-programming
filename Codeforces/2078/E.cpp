/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-03-11
 * Contest: Codeforces 2078
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

void solve(){
    ll a = 0, b = 0;

    rep(i, 0, 30){
        if (i % 2 == 0){
            a |= (1 << i);
        } else {
            b |= (1 << i);
        }
    }

    cout << a << endl;
    ll c1; cin >> c1;
    cout << b << endl;
    ll c2; cin >> c2;
    cout << "!" << endl;

    ll x = 0, y = 0;

    bool p = (c2 & 1);
    bool q = (c2 & 2);

    if (q){
        x |= 1;
        y |= 1;
    } else if (p){
        x |= 1;
    }

    rep(i, 1, 30){
        if (i % 2 == 1){
            bool p = (c1 & (1 << i));
            bool q = (c1 & (1 << (i + 1)));
            if (p && q){
                // 11
                x |= (1 << i);
                y |= (1 << i);
            } else if (!p){
                // 10
                x |= (1 << i);
            }
        } else {
            bool p = (c2 & (1 << i));
            bool q = (c2 & (1 << (i + 1)));
            if (p && q){
                // 11
                x |= (1 << i);
                y |= (1 << i);
            } else if (!p){
                // 10
                x |= (1 << i);
            }
        }
    }

    ll m; cin >> m;

    cout << (m | x) + (m | y) << endl;
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