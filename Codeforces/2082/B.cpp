/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-03-14
 * Contest: Codeforces 2082
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
    int x, n, m; cin >> x >> n >> m;

    if (x == 0){
        cout << 0 << " " << 0 << endl;
        return;
    }
    
    int xx = x;
    vi a;
    while(xx > 0){
        a.pb(x % 2);
        xx /= 2;
    }

    int l = a.size();

    if (n >= l){
        cout << 0 << " " << 0 << endl;
        return;
    }

    if (n + m >= l + 1){
        if (n == 0){
            cout << 1 << " " << 1 << endl;
            return;
        }

        cout << 0 << " " << 1 << endl;
        return;
    }

    int lo = x, hi = x;

    rep (i, 0, n){
        hi /= 2;
    }

    rep (i, 0, m){
        hi = (hi + 1)/2;
        lo = (lo + 1)/2;
    }

    rep(i, 0, n){
        lo /= 2;
    }

    cout << lo << " " << hi << endl;
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