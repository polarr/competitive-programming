/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-11-19
 * Contest: Codeforces 2156
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

void solve(){
    int n; cin >> n;

    vi arr(n);
    rep(i, 0, n) cin >> arr[i];

    auto remcheck = [&](int x, int i, vi deg) {
        rep(j, 0, i) {
            if (arr[j] <= arr[i] - x) {
                deg[j]--;
            }
        }

        deg[i] = 0;

        rep(j, i + 1, n) {
            if (arr[j] >= arr[i] + x) {
                deg[j]--;
            }
        }

        rep(i, 0, n){
            if (deg[i] >= 2) return true;
        }

        return false;
    };

    auto check = [&](int x) {
        vi curr;

        vi deg(n, 0);
        rep(i, 1, n){
            curr.pb(arr[i - 1]);
            sort(all(curr));
            if (sz(curr) == 4) {
                curr.pop_back();
            }

            deg[i] += upper_bound(all(curr), arr[i] - x) - curr.begin();
        }
        
        curr = {};
        for (int i = n - 2; i >= 0; i--){
            curr.pb(-arr[i + 1]);
            sort(all(curr));
            if (sz(curr) == 4) {
                curr.pop_back();
            }

            deg[i] += upper_bound(all(curr), -arr[i] - x) - curr.begin();
        }

        int big = -1;
        vi two;
        rep(i, 0, n){
            if (deg[i] == 2) {
                two.pb(i);
            }

            if (deg[i] >= 3) {
                if (big != -1) return true;
                big = i;
            }
        }

        if (big != -1) {
            return remcheck(x, big, deg);
        }

        if (sz(two) >= 4) return true;
        if (sz(two) <= 1) return false;

        rep(i, 0, sz(two)) {
            bool good = remcheck(x, two[i], deg);
            if (!good) return false;
        }

        return true;
    };

    int lo = -1e9, hi = 1e9;
    while (lo < hi){
        int mid = lo + (hi - lo + 1)/2;

        if (check(mid)){
            lo = mid;
        } else {
            hi = mid - 1;
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