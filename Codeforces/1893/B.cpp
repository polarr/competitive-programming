/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-07-30
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
    int n, m; cin >> n >> m;
    vi a(n), b(m);
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, m) cin >> b[i];

    sort(all(b));
    reverse(all(b));

    vi ans;
    vi rans;

    int lo = 0, hi = m - 1;
    rep(i, 0, (n + 1)/2){
        while (lo <= hi && b[lo] >= a[i]){
            ans.pb(b[lo]);
            lo++;
        }

        while (lo <= hi && b[hi] <= a[n - 1 - i]){
            rans.pb(b[hi]);
            hi--;
        }

        ans.pb(a[i]);
        if (2 * i + 1 != n){
            rans.pb(a[n - 1 - i]);
        }
    }

    while (lo <= hi){
        ans.pb(b[lo]);
        lo++;
    }

    reverse(all(rans));
    rep(i, 0, ans.size()){
        cout << ans[i] << " ";
    }
    rep(i, 0, rans.size()){
        cout << rans[i] << " ";
    }

    cout << endl;

    // vi lis(n + 1, INT_MAX);
    // lis[0] = 0;
    // int mx = 0;
    // vi l(n, 0);
    // rep(i, 0, n){
    //     int j = lower_bound(all(lis), a[i]) - lis.begin();
    //     lis[j] = min(lis[j], a[i]);
    //     if (j > mx) mx = j;
    //     l[i] = mx;
    // }

    // cerr << mx << endl;

    // int j = 0;
    // bool found = false;

    // vi ans;

    // rep(i, 0, n){
    //     if (!found && l[i] == mx){
    //         found = true;
    //     }

    //     if (found && a[i] >= lis[mx]){
    //         while (j < m && b[j] >= a[i]){
    //             ans.pb(b[j]);
    //             j++;
    //         }
    //     }

    //     ans.pb(a[i]);
    // }

    // rep(i, j, m){
    //     ans.pb(b[i]);
    // }

    // rep(i, 0, ans.size()){
    //     cout << ans[i] << " ";
    // }
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