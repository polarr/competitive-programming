/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-07-30
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
    int m; cin >> m;
    vl total(m);
    map<ll, ll> mp1, mp2;
    ll mn = 0, mx = 0;
    ll sumn = 0;
    rep(i, 0, m){
        ll n, l, r; cin >> n >> l >> r;
        mn += l;
        mx += r;
        sumn += n;

        vector<pair<ll, ll>> elements(n);
        rep(j, 0, n) {
            cin >> elements[j].first;
        }

        rep(j, 0, n){
            cin >> elements[j].second;
            total[i] += elements[j].second;
        }

        rep(j, 0, n){
            ll x = elements[j].first, c = elements[j].second;
            mp1[x] += max(l - total[i] + c, 0LL);
            mp2[x] += r - min(total[i] - c, r);
        }
    }

    if (mx - mn + 1 > sumn){
        cout << 0 << endl;
        return;
    }

    ll ans = LLONG_MAX;

    for (ll x = mn; x <= mx; x++){
        ll contrib = max(mp1[x], max(x + mp2[x] - mx, 0LL));
        ans = min(ans, contrib);
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