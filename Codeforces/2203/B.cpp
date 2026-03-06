/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2026-03-05
 * Contest: 
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
    ll x; cin >> x;

    vi arr;

    ll sum = 0;
    ll xx = x;
    while (xx > 0) {
        sum += xx % 10;
        arr.pb(xx % 10);
        xx /= 10;
    }

    vi sub;
    rep(i, 0, sz(arr)) {
        int c = arr[i];
        if (i == sz(arr) - 1) {
            --c;
        }

        sub.pb(c);
    }

    int ans = 0;
    sort(all(sub));
    reverse(all(sub));
    rep(i, 0, sz(sub)) {
        if (sum < 10) break;
        ans++;
        sum -= sub[i];
    }

    cout << ans << endl;
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