/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-03-13
 * Contest: Codeforces 2067
 * Problem: C
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

    vi a;

    int nn = n;
    while (nn > 0){
        a.pb(nn % 10);
        nn /= 10;
    }

    rep(i, 0, a.size()){
        if (a[i] == 7){
            cout << 0 << endl;
            return;
        }
    }

    int mn = 7;

    int unit = a[0];

    if (unit > 7){
        mn = unit - 7;
    }

    int nx = -1;

    rep(i, 1, a.size()){
        if (a[i] == 0){
            continue;
        }

        if (nx == -1){
            nx = a[i];
            continue;
        }

        if (a[i] < 7){
            mn = min(mn, 7 - a[i]);
        }
    }

    if (nx == 8){
        mn = min(mn, unit + 1);
    }

    if (nx < 7){
        int d = 7 - nx;
        if (d > unit){
            d++;
        }

        mn = min(mn, d);
    }

    mn = min(mn, unit + 3);

    cout << mn << endl;
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