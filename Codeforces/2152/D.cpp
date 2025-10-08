/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-10-03
 * Contest: 
 * Problem: D
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

const int MAX_N = 1e9;
const ll MOD = 1e9 + 7;

map<int, bool> pow2;

void solve(){
    int n, q; cin >> n >> q;
    vi arr(n);
    rep(i, 0, n) cin >> arr[i];
    vi pre(n + 1, 0), pw(n + 1, 0), pwo(n + 1, 0);
    rep(i, 0, n){
        int a = 0;
        int x = arr[i];
        while (x > 1){
            x /= 2;
            a++;
        }
        pre[i + 1] = pre[i] + a;
        pw[i + 1] = pw[i];
        pwo[i + 1] = pwo[i];
        if (pow2[arr[i]]){
            pw[i + 1]++;
        }
        if (pow2[arr[i] - 1]){
            pwo[i + 1]++;
        }
    }

    rep(i, 0, q){
        int l, r; cin >> l >> r;
        int num = r - l + 1;
        int ans = pre[r] - pre[l - 1];
        int p = pw[r] - pw[l - 1];
        int po = pwo[r] - pwo[l - 1];
        ans += num - p;
        ans -= (po + 1)/2;

        cout << ans << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int curr = 2;
    while (curr <= MAX_N){
        pow2[curr] = true;
        curr *= 2;
    }

    int tc;
    cin >> tc;
    for (int t = 1; t <= tc; ++t){
        // cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}