/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-12-22
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
    int n, k; cin >> n >> k;

    int lg = log2(1e9);
    int cnt = 0;
    vector<bool> less(k, false);
    vi ans(k, 0);

    for (int pw = lg; pw >= 0; pw--) {
        int bit = (1 << pw);
        bool has = n & bit;

        if (!has) {
            int take = 0;
            // 0, need even 1
            rep(i, 0, k) {
                if (!less[i]) continue;
                if (take >= 2 * (cnt/2)) {
                    break;
                }

                take++;
                ans[i] |= bit;
            }
            continue;
        }

        int take = 0;
        int mx = (k % 2 == 0 ? k - 1 : k);
        rep(i, 0, k) {
            if (!less[i]) continue;
            if (take >= mx) break;
            take++;
            ans[i] |= bit;
        }

        rep(i, 0, k) {
            if (less[i]) continue;
            if (take >= mx) {
                less[i] = true;
                cnt++;
            } else {
                take++;
                ans[i] |= bit;
            }
        }
    }

    rep(i, 0, k) {
        cout << ans[i] << " ";
    }

    cout << "\n";
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