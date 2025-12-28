/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-12-27
 * Contest: 
 * Problem: E
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

ll ask(int l, int r) {
    cout << "? " << l + 1 << " " << r + 1 << endl;
    ll ans; cin >> ans;
    return ans;
}

void solve(){
    int n; cin >> n;

    function<void(int, int)> rec;
    rec = [&](int l, int r) {
        ll all = ask(l, r);

        if (l == r) {
            cout << "! " << all << endl;
            return;
        }

        int lo = l, hi = r;
        while (lo < hi) {
            int mid = (lo + hi + 1)/2;

            ll sum = ask(l, mid);
            if (sum <= all/2) {
                lo = mid;
            } else {
                hi = mid - 1;
            }
        }

        // l ... lo, lo + 1 ... r
        int a = lo - l + 1;
        int b = r - lo;
        if (a > b) {
            rec(lo + 1, r);
        } else {
            rec(l, lo);
        }
    };

    rec(0, n - 1);
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