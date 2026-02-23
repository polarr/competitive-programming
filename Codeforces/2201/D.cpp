/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2026-02-23
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

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

struct SubarrayCount {
    ll cnt = 0;
    map<int, bool> has;
    set<int> endpoints;

    ll count(ll x) {
        return (x * (x + 1))/2;
    }

    void add(int a) {
        if (has[a]) return;
        has[a] = true;

        int both = 0;

        ll ohi = a, olo = a;
        if (has[a - 1]) {
            both++;
            ll hi = a - 1, lo = a - 1;
            auto j = endpoints.find(a - 1);
            if (has[a - 2]) {
                lo = *prev(j);
                endpoints.erase(j);
            }

            olo = lo;

            cnt -= count(hi - lo + 1);
        }

        if (has[a + 1]) {
            both++;
            ll hi = a + 1, lo = a + 1;
            auto j = endpoints.find(a + 1);
            if (has[a + 2]) {
                hi = *next(j);
                endpoints.erase(j);
            }

            ohi = hi;

            cnt -= count(hi - lo + 1);
        }

        if (both != 2) {
            endpoints.insert(a);
        }

        cnt += count(ohi - olo + 1);
    }

    void remove(int a) {
        if (!has[a]) return;
        has[a] = false;

        endpoints.insert(a);
        auto j = endpoints.find(a);

        ll hi = a, lo = a;
        if (has[a - 1]) {
            lo = *prev(j);
            endpoints.insert(a - 1);
        }
        if (has[a + 1]) {
            hi = *next(j);
            endpoints.insert(a + 1);
        }

        endpoints.erase(j);
        cnt -= count(hi - lo + 1);
        cnt += count(a - lo);
        cnt += count(hi - a);
    }

    ll num() {
        return cnt;
    }
};

void solve(){
    int n, q; cin >> n >> q;

    vi arr(n);
    rep(i, 0, n) {
        cin >> arr[i];
        --arr[i];
    }

    set<int> mx;
    vector<SubarrayCount> ans(n);
    vector<set<int>> pos(n);

    rep(i, 0, n) {
        int x = arr[i];
        pos[x].insert(i);
    }

    auto add = [&](int d, int i) {
        ans[d].add(i);
        mx.insert(d);
    };

    auto remove = [&](int d, int i) {
        ans[d].remove(i);
        if (ans[d].num() == 0) {
            mx.erase(d);
        }
    };

    rep(i, 0, n) {
        if (sz(pos[i]) < 2) continue;
        int hi = *prev(pos[i].end()), lo = *pos[i].begin();
        add(hi - lo, lo);
    }

    auto modify = [&](int i, int y) {
        int x = arr[i];
        if (sz(pos[x]) >= 2) {
            int hi = *prev(pos[x].end()), lo = *pos[x].begin();
            remove(hi - lo, lo);
        }

        pos[x].erase(i);
        if (sz(pos[x]) >= 2) {
            int hi = *prev(pos[x].end()), lo = *pos[x].begin();
            add(hi - lo, lo);
        }

        arr[i] = y;
        if (sz(pos[y]) >= 2) {
            int hi = *prev(pos[y].end()), lo = *pos[y].begin();
            remove(hi - lo, lo);
        }

        pos[y].insert(i);
        if (sz(pos[y]) >= 2) {
            int hi = *prev(pos[y].end()), lo = *pos[y].begin();
            add(hi - lo, lo);
        }
    };

    rep(qq, 0, q) {
        int i, x; cin >> i >> x;
        --i; --x;

        modify(i, x);

        int k = 0;
        if (!mx.empty()) {
            k = *prev(mx.end());
        }

        int f = 0;
        if (k > 0) {
            f = ans[k].num();
        }

        cout << k << " " << f << '\n';
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