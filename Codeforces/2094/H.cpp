/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-09-17
 * Contest: Codeforces 2094
 * Problem: H
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

vector<vi> divs(MAX_N);

void solve(){
    vi has;
    int n, q; cin >> n >> q;  

    vi arr(n);
    rep(i, 0, n) {
        cin >> arr[i];
        divs[arr[i]].pb(i);
        has.pb(arr[i]);
    }

    rep(ii, 0, q){
        int k, l, r; cin >> k >> l >> r;
        --l; --r;
        ll ans = 0;
        int curr = l;
        while (curr <= r){
            int mn = r + 1;
            int j = 0;

            if (k == 1){
                ans += (r + 1 - curr);
                break;
            }

            rep(i, 1, sqrt(k) + 1){
                if (k % i != 0) continue;
                if (i != 1){
                    int x = i;
                    auto nx = lower_bound(all(divs[x]), curr);
                    if (nx != divs[x].end()){
                        if (*nx < mn) {
                            mn = *nx;
                            j = x;
                        }
                    }
                }
                int x = k/i;
                auto nx = lower_bound(all(divs[x]), curr);
                if (nx != divs[x].end()){
                    if (*nx >= mn) {
                        continue;
                    }
                    mn = *nx;
                    j = x;
                }
            }

            ans += (ll) k * (mn - curr);
            while (j != 0 && k % j == 0){
                k /= j;
            }
            curr = mn;
        }

        cout << ans << endl;
    }

    for (int x : has){
        divs[x] = {};
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