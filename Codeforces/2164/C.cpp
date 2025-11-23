/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-11-22
 * Contest: Codeforces 2164
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
    int n, m; cin >> n >> m;

    multiset<int> swords;
    vi bad;
    vector<pii> good;
    vector<pii> monster(m);
    rep(i, 0, n) {
        int a; cin >> a;
        swords.insert(a);
    }
    rep(i, 0, m) {
        cin >> monster[i].first;
    }
    rep(i, 0, m) cin >> monster[i].second;
    rep(i, 0, m) {
        if (monster[i].second == 0) {
            bad.pb(monster[i].first);
        } else {
            good.pb(monster[i]);
        }
    }
    int ans = 0;
    sort(all(bad));
    sort(all(good));
    rep(i, 0, sz(good)) {
        int h = good[i].first;
        int c = good[i].second;

        auto j = swords.lower_bound(h);
        if (j == swords.end()) {
            continue;
        }

        int nw = max(*j, c);
        ans++;
        swords.erase(j);
        swords.insert(nw);
    }

    rep(i, 0, sz(bad)) {
        auto j = swords.lower_bound(bad[i]);
        if (j == swords.end()) break;

        ans++;
        swords.erase(j);
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