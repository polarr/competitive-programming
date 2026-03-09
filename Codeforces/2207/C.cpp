/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2026-03-08
 * Contest: 
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
    ll h; cin >> h;
    
    vl arr(n);
    rep(i, 0, n) {
        cin >> arr[i];
    }

    vl l(n), r(n);

    stack<pii> s;
    rep(i, 0, n) {
        ll x = arr[i];
        while (!s.empty() && s.top().first <= x) {
            s.pop();
        }

        int idx = -1;
        ll val = 0;
        if (!s.empty()) {
            idx = s.top().second;
            val = l[idx];
        }

        l[i] = (ll)(i - idx) * (h - x) + val;
        s.push({x, i});
    }

    s = {};

    for (int i = n - 1; i >= 0; i--) {
        ll x = arr[i];
        while (!s.empty() && s.top().first <= x) {
            s.pop();
        }

        int idx = n;
        ll val = 0;
        if (!s.empty()) {
            idx = s.top().second;
            val = r[idx];
        }

        r[i] = (ll)(idx - i) * (h - x) + val;
        s.push({x, i});
    }

    vl drain(n);
    rep(i, 0, n) {
        drain[i] = l[i] + r[i] - (h - arr[i]);
    }

    ll ans = *max_element(all(drain));

    rep(i, 0, n) {
        ll mx = arr[i];
        int mxi = i;
        rep(j, i + 1, n) {
            if (arr[j] > mx) {
                mx = arr[j];
                mxi = j;
            }

            ans = max(ans, drain[i] + drain[j] - drain[mxi]);
        }
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