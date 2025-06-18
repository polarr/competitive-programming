/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-06-17
 * Contest: Codeforces 2114
 * Problem: g
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

vl pow2(31, 1);

void solve(){
    ll n, k; cin >> n >> k;

    if (k < n){
        cout << "NO" << endl;
        return;
    }

    vector<pii> a(n);
    rep(i, 0, n){
        int x; cin >> x;

        int pw = 0;
        while (x % 2 == 0){
            x /= 2;
            pw++;
        }

        a[i] = {x, pw};
    }

    vl l(n), r(n);
    rep(i, 0, n){
        if (i == 0 || a[i - 1].first != a[i].first){
            l[i] = pow2[a[i].second];
        } else {
            if (a[i - 1].second > a[i].second){
                l[i] = pow2[a[i].second];
            } else {
                l[i] = pow2[a[i].second] - pow2[a[i - 1].second + 1] + 1;
            }
        }

        if (i == n - 1 || a[i].first != a[i + 1].first){
            r[i] = pow2[a[i].second];
        } else {
            if (a[i + 1].second > a[i].second){
                r[i] = pow2[a[i].second];
            } else {
                r[i] = pow2[a[i].second] - pow2[a[i + 1].second + 1] + 1;
            }
        }
    }

    ll mx = 0, curr = 0;
    rep(i, 0, n){
        curr += l[i];
    }

    rep(i, 0, n){
        curr -= l[i];
        curr += pow2[a[i].second];
        mx = max(mx, curr);

        curr -= pow2[a[i].second];
        curr += r[i];
    }

    if (mx >= k){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    rep(i, 1, 31){
        pow2[i] = pow2[i - 1] * 2;
    }

    int tc;
    cin >> tc;
    for (int t = 1; t <= tc; ++t){
        // cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}