/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-11-10
 * Contest: Codeforces 2163
 * Problem: D2
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

    using T = array<int, 2>;
    vector<T> srange(q), range;
    rep(i, 0, q){
        int l, r; cin >> l >> r;
        srange[i] = {l, r};
    }

    sort(all(srange));

    int pre = 0;
    rep(i, 0, q){
        if (i == q - 1 || srange[i][0] != srange[i + 1][0]){
            if (srange[i][1] > pre) {
                range.pb(srange[i]);
                pre = srange[i][1];
            }
        }
    }

    auto ask = [&](int l, int r) -> int {
        cout << "? " << l << " " << r << endl;
        int ans; cin >> ans;
        return ans;
    };

    int k = sz(range);
    int lo = 0, hi = k - 1;
    while (lo < hi){
        int mid = (lo + hi)/2;

        int x = ask(1, range[mid][1]);
        int y = ask(range[mid][0], n);

        if (x >= y){
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }

    int ans = ask(range[lo][0], range[lo][1]);

    if (lo > 0){
        ans = max(ans, ask(range[lo - 1][0], range[lo - 1][1]));
    }

    cout << "! " << ans << endl;
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