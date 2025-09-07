/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-09-06
 * Contest: Codeforces 86
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

void solve(){
    int n, q; cin >> n >> q;
    
    vl arr(n);
    rep(i, 0, n) cin >> arr[i];
    vector<array<int, 3>> queries(q);
    rep(i, 0, q){
        int a, b; cin >> a >> b;
        --a; --b;
        queries[i] = {a, b, i};
    }

    /** ALGORITHM: Mo's Algorithm
     *  PURPOSE: Query comparison function for Mo's order
     *  SOURCE: O((n + q) * sqrt(n) * f) where is time for each change
    */
    int rt = (int)sqrt(n);
    auto mo_cmp = [&](array<int, 3> a, array<int, 3> b) {
        int block_a = a[0] / rt;
        int block_b = b[0] / rt;
        if (block_a == block_b) { return a[1] < b[1]; }
        return block_a < block_b;
    };

    sort(all(queries), mo_cmp);

    ll curr = 0;
    vl nums(1e6 + 1, 0);

    int l = 0, r = -1;

    auto add = [&](int i){
        ll x = arr[i];
        curr -= nums[x] * nums[x] * x;
        nums[x]++;
        curr += nums[x] * nums[x] * x;
    };

    auto remove = [&](int i){
        ll x = arr[i];
        curr -= nums[x] * nums[x] * x;
        nums[x]--;
        curr += nums[x] * nums[x] * x;
    };

    vl ans(q);

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

        ans[j] = curr;
    }

    for (ll a : ans){
        cout << a << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}