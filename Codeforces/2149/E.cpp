/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-09-25
 * Contest: 
 * Problem: E
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
    int n, k, l, r; cin >> n >> k >> l >> r;

    vi arr(n);
    rep(i, 0, n){
        cin >> arr[i];
    }

    map<int, int> compress;
    vi brr = arr;
    sort(all(brr));
    int cc = 0;
    rep(i, 0, n){
        if (i == 0 || brr[i] != brr[i - 1]){
            compress[brr[i]] = cc;
            cc++;
        }
    }

    rep(i, 0, n){
        arr[i] = compress[arr[i]];
    }

    vi last(n, -1);
    set<pii> lastIndices;

    int distinct = 0;
    int mx = 0;
    int mn = -1;
    ll ans = 0;
    rep(i, 0, n){
        int x = arr[i];
        if (last[x] == -1){
            distinct++;
        }

        if (distinct >= k + 1 && last[x] < mx){
            mn = mx;
        }

        lastIndices.erase({last[x], x});
        last[x] = i;
        lastIndices.insert({last[x], x});
        if (lastIndices.size() > k){
            lastIndices.erase(lastIndices.begin());
        }

        if (distinct >= k){
            auto j = lastIndices.begin();
            mx = (*j).first;

            int hi = min(i - l + 1, mx);
            int lo = max(i - r + 1, mn + 1);

            // cout << i << " " << lo << " " << hi << endl;

            ans += max(0, hi - lo + 1);
        }
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