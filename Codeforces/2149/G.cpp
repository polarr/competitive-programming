/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-09-25
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

// No bruh just simple sqrt decomp smh...

void solve(){
    int n, q; cin >> n >> q;

    vector<vi> ans(q);
    vi arr(n);
    rep(i, 0, n){
        cin >> arr[i];
    }

    vi brr = arr;
    sort(all(brr));

    map<int, int> compress;
    vi rev(n);
    int cc = 0;
    rep(i, 0, n){
        if (i == 0 || brr[i] != brr[i - 1]){
            compress[brr[i]] = cc;
            rev[cc] = brr[i];
            cc++;
        }
    }

    rep(i, 0, n) arr[i] = compress[arr[i]];

    vector<array<int, 3>> queries;
    rep(i, 0, q){
        int l, r; cin >> l >> r;
        queries.pb({l - 1, r - 1, i});
    }

    /** ALGORITHM: Mo's Algorithm
     *  PURPOSE: Query comparison function for Mo's order
     *  SOURCE: O((n + q) * sqrt(n) * f) where is time for each change
    */
    int block_size = (int)sqrt(n);
    auto mo_cmp = [&](array<int, 3> a, array<int, 3> b) {
        int block_a = a[0] / block_size;
        int block_b = b[0] / block_size;
        if (block_a == block_b) { return a[1] < b[1]; }
        return block_a < block_b;
    };

    sort(all(queries), mo_cmp);

    vi nums(n, 0);
    set<pii> s;

    int l = 0, r = -1;

    auto add = [&](int i){
        ll x = arr[i];
        s.erase({nums[x], x});
        nums[x]++;
        s.insert({nums[x], x});
    };

    auto remove = [&](int i){
        ll x = arr[i];
        s.erase({nums[x], x});
        nums[x]--;
        s.insert({nums[x], x});
    };

    rep(i, 0, q){
        auto &[a, b, j] = queries[i];

        while (l < a){
            remove(l);
            l++;
        }
        while (l > a){
            l--;
            add(l);
        }
        while (r < b){
            r++;
            add(r);
        }
        while (r > b){
            remove(r);
            r--;
        }

        int target = (b - a + 1)/3;

        auto it = s.end();
        it--;
        if ((*it).first > target){
            ans[j].pb(rev[(*it).second]);
        }

        if (it != s.begin()){
            it--;
            if ((*it).first > target){
                ans[j].pb(rev[(*it).second]);
            }
        }
    }

    rep(i, 0, q){
        if (ans[i].size() == 0){
            cout << -1 << endl;
            continue;
        }

        sort(all(ans[i]));
        for (int a : ans[i]){
            cout << a << " ";
        }

        cout << endl;
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