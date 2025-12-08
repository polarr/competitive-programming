/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-12-07
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
    int s, k; cin >> s >> k;

    if (s % k == 0) {
        cout << k << endl;
        return;
    }

    if (s > k * k) {
        cout << max(1, k - 2) << endl;
        return;
    }

    vector<bool> can(s + 1, false);
    can[0] = true;
    bool up = true;
    while (k > 0 && !can[s]) {
        vector<bool> ncan(s + 1, false);
        if (up) {
            for (int i = s; i >= 0; i--) {
                if (!can[i]) continue;

                for (int j = i + k; j <= s; j += k) {
                    if (ncan[j]) {
                        break;
                    }

                    ncan[j] = true;
                }
            }
        } else {
            rep(i, 0, s + 1) {
                if (!can[i]) continue;

                for (int j = i - k; j >= 0; j -= k) {
                    if (ncan[j]) {
                        break;
                    }

                    ncan[j] = true;
                }
            }
        }

        can = ncan;
        k--;
        up = !up;
    }

    cout << k + 1 << endl;
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