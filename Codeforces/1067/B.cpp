/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-11-29
 * Contest: 
 * Problem: B
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
    vi cnta(2 * n, 0);
    rep(i, 0, 2 * n) {
        int x; cin >> x;
        --x;
        cnta[x]++;
    }

    int bal = 0;
    int ans = 0;
    int p = 0, q = 0;
    rep(i, 0, 2 * n) {
        if (cnta[i] == 0) continue;
        if (cnta[i] % 2 == 1) {
            ans++;
            if (bal > 0) {
                bal--;
            } else {
                bal++;
            }
            p++;
        } else {
            if (cnta[i]/2 % 2 == 1) {
                ans += 2;
                continue;
            }

            ans += 2;
            if (bal > 0) {
                bal -= 2;
            } else {
                bal += 2;
            }
            q++;
        }
    }

    if (bal != 0) {
        if (p == 0) {
            ans -= 2;
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