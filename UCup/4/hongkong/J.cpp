/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2026-01-31
 * Contest: 
 * Problem: J
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
    vector<pair<ll, ll>> dept(3);
    rep(i, 0, 3) {
        ll x; cin >> x;
        dept[i] = {x, i};
    }

    sort(all(dept));
    vi ord(3);
    rep(i, 0, 3) {
        ord[dept[i].second] = i;
    }

    vl sum(3, 0);
    vector<multiset<ll>> p(3);
    rep(i, 0, n) {
        int per, c; cin >> per >> c;
        int real = ord[--per];
        p[real].insert(c);
        sum[real] += c;
    }

    ll need; cin >> need;
    ll penalty = 0;
    ll time = 0;

    auto check = [&](ll c, int j) -> bool {
        sum[j] -= c;
        time += c;
        bool ans = true;
        ll curr = 0;
        rep(i, 0, 3) {
            curr += sum[i];
            if ((i >= j || curr != 0) && time + curr > dept[i].first) {
                ans = false;
                break;
            }
        }
        sum[j] += c;
        time -= c;

        return ans;
    };


    while (!p[0].empty() || !p[1].empty() || !p[2].empty()) {
        vector<pair<ll, ll>> x(3);
        rep(i, 0, 3) {
            x[i] = {1e9, i};
        }
        if (!p[0].empty()) x[0].first = *p[0].begin();
        if (!p[1].empty()) x[1].first = *p[1].begin();
        if (!p[2].empty()) x[2].first = *p[2].begin();

        sort(all(x));

        bool good = false;
        rep(i, 0, 3) {
            auto [c, j] = x[i];
            if (c == 1e9) continue;
            if (check(c, j)) {
                good = true;
                time += c;
                penalty += time;
                p[j].erase(p[j].begin());
                sum[j] -= c;
                break;
            }
        }

        if (!good) {
            cout << "NO\n";
            return;
        }
    }

    if (penalty >= need) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
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