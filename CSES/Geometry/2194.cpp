/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2026-01-11
 * Contest: CSES Problemset
 * Problem: 2194
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

using pt = array<ll, 2>;

void solve(){
    int n; cin >> n;
    vector<pt> points(n);
    rep(i, 0, n) {
        int x, y; cin >> x >> y;
        points[i] = {x, y};
    }

    sort(all(points));

    ll ans = 9e18;
    ll rt = 3e18;

    set<pt> activey;
    
    int j = 0;

    rep(i, 0, n) {
        pt point = points[i];
        pt revpt = {point[1], point[0]};

        while (points[j][0] < point[0] - rt) {
            activey.erase({points[j][1], points[j][0]});
            j++;
        }

        auto j = activey.lower_bound(pt{point[1] - rt, -(ll)1e9});
        while (j != activey.end() && (*j)[0] <= point[1] + rt) {
            pt cand = *j;
            ll d = (revpt[0] - cand[0]) * (revpt[0] - cand[0]) + (revpt[1] - cand[1]) * (revpt[1] - cand[1]);
            ll rtd = sqrt(d);

            if (d < ans) {
                ans = d;
                rt = rtd;
            }

            j++;
        }

        activey.insert(revpt);
    }

    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}