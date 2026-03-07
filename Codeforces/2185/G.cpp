/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2026-03-06
 * Contest: 
 * Problem: G
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

    vector<vi> arrs(n);
    vector<vi> cnt(n);
    vector<pii> mex(n);

    ll tot = 0;
    ll ans = 0;

    map<int, ll> want;

    rep(i, 0, n) {
        int m; cin >> m;
        cnt[i] = vi(m + 3, 0);

        rep(j, 0, m) {
            int x; cin >> x;
            arrs[i].pb(x);

            if (x < m + 3) {
                cnt[i][x]++;
            }
        }

        int no = 0;
        rep(x, 0, m + 3) {
            if (cnt[i][x] == 0) {
                if (no == 0) {
                    mex[i].first = x;
                    no++;
                } else {
                    mex[i].second = x;
                    break;
                }
            }
        }

        tot += mex[i].first;
        want[mex[i].first] += mex[i].second - mex[i].first;
    }

    rep(i, 0, n) {
        int m = sz(arrs[i]);
        rep(j, 0, m) {
            int x = arrs[i][j];

            ll base = tot;
            if (x < mex[i].first && cnt[i][x] == 1) {
                base -= mex[i].first;
                base += x;
            }

            ans += base * (n - 1) + want[x];
        }
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