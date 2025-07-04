/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-07-04
 * Contest: Codeforces 2123
 * Problem: G
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

const int MAX_N = 5e5 + 1;
const ll MOD = 1e9 + 7;

vector<vi> d(MAX_N);

void solve(){
    int n, m, q; cin >> n >> m >> q;

    vi a(n);
    rep(i, 0, n) cin >> a[i];

    int k = d[m].size();
    vi invalid(k, 0);

    auto process = [&](int i, bool sub = false){
        if (i < 0 || i >= n - 1) return;
        int x = a[i], y = a[i + 1];
        rep(j, 0, k){
            int div = d[m][j];
            if (!sub) invalid[j] += ((x % div) > (y % div));
            if (sub) invalid[j] -= ((x % div) > (y % div));
        }
    };

    rep(i, 0, n - 1){
        process(i);
    }

    rep(i, 0, q){
        int c; cin >> c;
        if (c == 1){
            int j, x; cin >> j >> x;
            --j;
            process(j - 1, true);
            process(j, true);
            a[j] = x;
            process(j - 1);
            process(j);
            continue;
        }

        int x; cin >> x;
        int g = gcd(x, m);
        int r = m/g;
        int j = lower_bound(all(d[m]), g) - d[m].begin();
        if (invalid[j] > r - 1){
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    rep(i, 1, MAX_N){
        for (int j = i; j < MAX_N; j += i){
            d[j].pb(i);
        }
    }

    int tc;
    cin >> tc;
    for (int t = 1; t <= tc; ++t){
        // cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}