/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-06-09
 * Contest: Codeforces 877
 * Problem: F
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
    int n; ll k; cin >> n >> k;

    vi which(n); vl a(n + 1, 0);
    rep(i, 0, n){
        cin >> which[i];
    }

    ll last = 0;

    rep(i, 0, n){
        ll mult = 1;
        if (which[i] == 2){
            mult = -1;
        }

        cin >> a[i + 1];
        a[i + 1] *= mult;

        a[i + 1] += last;
        last = a[i + 1];
    }

    map<ll, int> compress;
    vl b = a;
    sort(all(b));
    int cnt = 0;
    rep(i, 0, n + 1){
        if (i == 0 || b[i] != b[i - 1]){
            compress[b[i]] = cnt++;
        }
    }

    vector<pair<int, int>> adj(n + 1, {n + 1, n + 1});

    rep(i, 0, n + 1){
        ll lo = a[i] - k, hi = a[i] + k;
        a[i] = compress[a[i]];
        if (compress.contains(lo)){
            adj[a[i]].first = compress[lo];
        }

        if (compress.contains(hi)){
            adj[a[i]].second = compress[hi];
        }
    }

    int q; cin >> q;

    vector<array<int, 3>> queries(q);
    rep(i, 0, q){
        int l, r; cin >> l >> r;
        queries[i] = {l, r, i};
    }

    int rt = sqrt(n);

    auto cmp = [&](array<int, 3> &a, array<int, 3> &b){
        if (a[0]/rt < b[0]/rt){
            return true;
        }

        return a[0]/rt == b[0]/rt && a[1] < b[1];
    };

    sort(all(queries), cmp);

    vl ans(q);
    vl has(n + 2, 0);
    ll curr = 0;

    auto move = [&](int i, bool add, bool front){
        int aj = adj[a[i]].second;
        if (front){
            aj = adj[a[i]].first;
        }

        if (add){
            curr += has[aj];
            has[a[i]]++;
            return;
        }

        has[a[i]]--;
        curr -= has[aj];
    };

    has[a[0]]++;
    move(1, true, true);

    pii range = {1, 1};
    rep(i, 0, q){
        auto [l, r, j] = queries[i];

        while (range.second < r){
            move(++range.second, true, true);
        }

        while (range.second > r){
            move(range.second--, false, true);
        }

        while (range.first < l){
            move(-1 + range.first++, false, false);
        }

        while (range.first > l){
            move(-1 + --range.first, true, false);
        }

        ans[j] = curr;
    }

    rep(i, 0, q){
        cout << ans[i] << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}