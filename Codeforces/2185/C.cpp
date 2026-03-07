/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2026-03-06
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

    vi arr(n);
    rep(i, 0, n) cin >> arr[i];
    sort(all(arr));

    vi brr;

    rep(i, 0, n) {
        if (i == 0 || arr[i] != arr[i - 1]) {
            brr.pb(arr[i]);
        }
    }

    int curr = 1, ans = 1;
    rep(i, 1, sz(brr)) {
        if (brr[i] == brr[i - 1] + 1) {
            curr++;
        } else {
            curr = 1;
        }

        ans = max(ans, curr);
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