/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-10-03
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
    int n, q; cin >> n >> q;
    vi arr(n);
    rep(i, 0, n) cin >> arr[i];
    vi zero(n + 1, 0), one(n + 1, 0), par(n + 1, 0);
    rep(i, 0, n){
        zero[i + 1] = zero[i];
        one[i + 1] = one[i];
        par[i + 1] = par[i];
        if (arr[i] == 0){
            zero[i + 1]++;
            if (i % 2 == 0){
                par[i + 1]++;
            }
        } else {
            one[i + 1]++;
        }
    }

    rep(i, 0, q){
        int l, r; cin >> l >> r;
        int z = zero[r] - zero[l - 1];
        int o = one[r] - one[l - 1];
        int p = par[r] - par[l - 1];
        if (z % 3 != 0 || o % 3 != 0){
            cout << -1 << endl;
            continue;
        }

        int ans = (z + o)/3;
        if (z == o && (p == z || p == 0)){
            ans++;
        }

        cout << ans << endl;
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