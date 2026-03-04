/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2026-03-03
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
    int n; cin >> n;

    vi arr(n);
    rep(i, 0, n) cin >> arr[i];

    vi mx(n, 0);
    vi l(n, 0);
    int curr = 0;
    rep(i, 1, n) {
        if (arr[i - 1] > arr[i]) {
            l[i] = l[i - 1];
        } else {
            l[i] = i;
        }

        if (arr[i] > arr[curr]) {
            curr = i;
        }

        mx[i] = curr;
    }

    vi mn(n, n - 1);
    vi r(n, n - 1);
    curr = n - 1;
    for (int i = n - 2; i >= 0; i--) {
        if (arr[i + 1] > arr[i]) {
            r[i] = r[i + 1];
        } else {
            r[i] = i;
        }

        if (arr[i] > arr[curr]) {
            curr = i;
        }

        mn[i] = curr;
    }

    int ans = 1;
    int inc = 1, dec = 1;

    // cout << inc << " " << dec << endl;
    int big = curr;
    while (big != 0) {
        int nx = mx[big - 1];

        inc++;
        ans = max(ans, inc);

        rep(i, nx + 1, big) {
            int left = max(nx + 1, l[i]);
            int right = min(big - 1, r[i]);

            ans = max(ans, inc + right - left + 1);
        }

        big = nx;
    }

    big = curr;
    while (big != n - 1) {
        int nx = mn[big + 1];

        dec++;
        ans = max(ans, dec);
        rep(i, big + 1, nx) {
            int left = max(big + 1, l[i]);
            int right = min(nx - 1, r[i]);

            ans = max(ans, dec + right - left + 1);
        }

        big = nx;
    }

    cout << n - ans << '\n';
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