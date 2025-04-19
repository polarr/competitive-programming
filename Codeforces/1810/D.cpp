/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-04-18
 * Contest: Codeforces 1810
 * Problem: D
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
    int q; cin >> q;
    pair<ll, ll> h = {1, LLONG_MAX};

    rep(i, 0, q){
        ll e; cin >> e;
        ll a, b; cin >> a >> b;
        ll d = a - b;

        ll t1 = max(0LL, (h.first - a + d - 1)/d) + 1;
        ll t2 = max(0LL, (h.second - a + d - 1)/d) + 1;

        if (e == 1){
            ll n; cin >> n;

            if (n >= t1 && n <= t2){
                cout << 1 << " ";
                pair<ll, ll> nh;
                if (n == 1){
                    nh = {1, a};
                } else {
                    nh = {(n - 2) * d + a + 1, (n - 1) * d + a};
                }

                h.first = max(h.first, nh.first);
                h.second = min(h.second, nh.second);
            } else {
                cout << 0 << " ";
            }

            continue;
        }

        if (t1 != t2){
            cout << -1 << " ";
        } else {
            cout << t1 << " ";
        }
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