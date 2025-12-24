/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-12-23
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
    rep(i, 0, n) {
        cin >> arr[i];
    }

    int lo = 1, hi = 1e9;
    while (lo < hi) {
        int k = (lo + hi + 1)/2;

        bool good = true;
        int below = 0;
        rep(i, 0, n) {
            if (arr[i] < k) {
                if (below == 0) {
                    below = arr[i];
                } else {
                    good = false;
                    break;
                }
            }
        }

        rep(i, 0, n) {
            if (arr[i] >= k && arr[i] - below < k) {
                good = false;
                break;
            }
        }

        if (good) {
            lo = k;
        } else {
            hi = k - 1;
        }
    }

    cout << lo << endl;
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