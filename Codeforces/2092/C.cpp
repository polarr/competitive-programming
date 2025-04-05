/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-04-04
 * Contest: Codeforces 2092
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
    vl a(n);
    int e = 0, o = 0;

    ll s = 0;
    ll mx = 0;
    rep(i, 0, n){
        cin >> a[i];
        s += a[i];
        mx = max(mx, a[i]);
        if (a[i] % 2 == 0){
            e++;
        } else {
            o++;
        }
    }

    if (o == 0 || e == 0){
        cout << mx << endl;
        return;
    }

    cout << s - (ll) o + 1 << endl;
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