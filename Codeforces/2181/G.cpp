/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2026-01-10
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

    ll sum = 0;
    vl scores(n);
    rep(i, 0, n) {
        ll x; cin >> x;
        scores[i] = x;
        sum += x;
    }

    sum /= 2;
    ll can = (n - 1);
    ll ans = (sum + can - 1)/can;

    vl pos = {0}, neg;
    rep(i, 1, n) {
        if (i % 2 == 1) {
            neg.pb(scores[i] - pos.back());
        } else {
            pos.pb(scores[i] - neg.back());
        }
    }

    ll mx_pos = *max_element(all(pos));
    ll mx_neg = *max_element(all(neg));
 
    ll lo = -(*min_element(all(pos)));
    ll hi = *min_element(all(neg));

    ll c = (mx_neg - mx_pos)/2;
    if (c < lo) {
        c = lo;
    }
    if (c > hi) {
        c = hi;
    }

    if (n % 2 == 1) {
        c = 0;
        rep(i, 1, n + 1) {
            if (i % 2 == 1) {
                c += scores[i % n];
            } else {
                c -= scores[i % n];
            }
        }

        c /= 2;
    }

    ll need = max(mx_pos + c, mx_neg - c);

    ans = max(ans, need);

    cout << ans << "\n";
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