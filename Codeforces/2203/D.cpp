/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2026-03-05
 * Contest: 
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
    int n, m; cin >> n >> m;

    int mx = n + m;

    vi can(mx + 1, 0);

    vi has(mx + 1, 0);
    rep(i, 0, n) {
        int x; cin >> x;
        has[x] = 1;
    }

    int g = 1;

    rep(i, 0, mx + 1) {
        if (has[i]) {
            if (g < mx + 1) g = lcm(g, i);
            for (int j = i; j < mx + 1; j += i) {
                can[j] = true;
            }
        }
    }

    int a = 0, b = 0, d = 0;
    rep(i, 0, m) {
        int x; cin >> x;
        if (can[x]) {
            a++;
        }

        if (x % g != 0) {
            b++;
        }

        if (can[x] && x % g != 0) {
            d++;
        }
    }

    // cout << a << b << d << endl;

    if (a > b) {
        cout << "Alice" << endl;
    } else if (b > a) {
        cout << "Bob" << endl;
    } else {
        if (d % 2 == 1) cout << "Alice" << endl;
        else cout << "Bob" << endl;
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