/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-12-08
 * Contest: 
 * Problem: F
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
    int n, q; cin >> n >> q;

    vl arr(n + 1, 0);
    rep(i, 1, n + 1) cin >> arr[i];

    int rt = sqrt(n * log2(n));

    vl suf(n + 2, 0), pre(n + 1, 0);
    for (int i = n; i >= 1; i--) {
        suf[i] = suf[i + 1] + arr[i];
    }
    rep(i, 1, n + 1) {
        pre[i] = pre[i - 1] + arr[i];
    }

    rep(qq, 0, q) {
        int l, r; cin >> l >> r;
        ll x; cin >> x;
        int curr = l;
        int refresh = 0;
        ll extra = 0;
        int len = 1;
        while (curr <= r) {
            if (curr + len > r + 1) {
                extra = suf[curr] - suf[r + 1];
                break;
            }

            while (len <= rt && suf[curr] - suf[min(n + 1, curr + len)] < x) {
                len++;
            }

            if (len > rt) {
                while (suf[curr] - suf[r + 1] >= x) {
                    int j = lower_bound(all(pre), pre[curr - 1] + x) - pre.begin();
                    refresh++;
                    curr = j + 1;
                }

                extra = suf[curr] - suf[r + 1];
                break;
            }

            if (curr + len > r + 1) {
                extra = suf[curr] - suf[r + 1];
                break;
            }

            int lo = curr, hi = r - len + 1; 
            while (lo < hi) {
                int mid = (lo + hi + 1)/2;
                if (suf[mid] - suf[mid + len] >= x) {
                    lo = mid;
                } else {
                    hi = mid - 1;
                }
            }

            int d = lo - curr + 1;
            int k = (d + len - 1)/len;
            curr += k * len;
            refresh += k;
        }

        cout << refresh << " " << extra << "\n";
    }
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