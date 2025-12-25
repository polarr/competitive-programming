/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-12-24
 * Contest: aaaa1
 * Problem: 2
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

    vector<pii> arr;
    rep(i, 0, n) {
        int x; cin >> x;
        arr.pb({x, 0});
    }

    rep(i, 0, m) {
        int x; cin >> x;
        arr.pb({x, 1});
    }

    sort(all(arr));

    ll ans = 0;
    ll mx = 0;
    rep(i, 0, n + m) {
        ll gap = i == 0 ? 1e9 : arr[i].first - arr[i - 1].first;
        mx = max(mx, gap);
        ans += gap;
        if (arr[i].second == 0) {
            ans -= mx;
            mx = 0;
        }
    }

    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    solve();
    return 0;
}