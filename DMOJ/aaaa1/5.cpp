/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-12-24
 * Contest: aaaa1
 * Problem: 5
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
    vl arr(n);
    rep(i, 0, n) cin >> arr[i];

    if (n == 1) {
        cout << 1 << endl;
        cout << (1 >= arr[0] ? 1 - arr[0] : 1 + arr[0]) << endl;
        return;
    }
    
    vi diffs(n - 1);
    rep(i, 1, n) {
        int d = abs(arr[i] - arr[i - 1]);
        diffs[i - 1] = arr[i] - arr[i - 1];
        if (d != 1) {
            cout << -1 << endl;
            return;
        }
    }

    int flip = 0;
    vi seq(n - 1);
    for (int i = n - 2; i >= 0; i--) {
        if (diffs[i] == -1 && flip == 0) {
            seq[i] = 1;
            flip = 1 - flip;
        }
        else if (diffs[i] == 1 && flip == 1) {
            seq[i] = 1;
            flip = 1 - flip;
        } else {
            seq[i] = 0;
        }
    }

    vl curr(n);
    rep(i, 0, n) {
        curr[i] = i + 1;
    }

    vl ans;

    rep(i, 0, n - 1) {
        if (seq[i] == 1) {
            ll d = max(curr[i], curr[i + 1]);
            ans.pb(d);

            rep(j, 0, n) {
                curr[j] = abs(curr[j] - d);
            }

            // rep(j, 0, n) {
            //     cout << curr[j] << " ";
            // }

            // cout << endl;
        }
    }

    ll mx = 0;
    rep(i, 0, n) {
        mx = max(mx, curr[i]);
    }

    if (curr[0] >= arr[0]) {
        ll d = curr[0] - arr[0];
        ans.pb(d);

        rep(j, 0, n) {
            curr[j] = abs(d - curr[j]);
        }

        // rep(j, 0, n) {
        //     cout << curr[j] << " ";
        // }

        // cout << endl;
    } else {
        ll d = curr[0] > arr[0] ? curr[0] - arr[0] : mx;
        ans.pb(d);

        rep(j, 0, n) {
            curr[j] = abs(d - curr[j]);
        }

        // rep(j, 0, n) {
        //     cout << curr[j] << " ";
        // }

        // cout << endl;

        d = curr[0] + arr[0];
        ans.pb(d);

        rep(j, 0, n) {
            curr[j] = abs(d - curr[j]);
        }

        // rep(j, 0, n) {
        //     cout << curr[j] << " ";
        // }

        // cout << endl;
    }

    // rep(j, 0, n) {
    //     cout << curr[j] << " ";
    // }

    // cout << endl;

    cout << sz(ans) << endl;

    rep(i, 0, sz(ans)) {
        cout << ans[i] << " ";
    }

    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}