/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2026-03-07
 * Contest: 
 * Problem: B
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

    vector<vi> children(n);
    rep(i, 1, n) {
        int x; cin >> x;
        --x;
        children[x].pb(i);
    }

    function<int(int, int)> dfs;
    dfs = [&](int node, int threshold) {
        if (children[node].empty()) {
            return node <= threshold ? 1 : -1;
        }

        int sum = 0;
        
        for (int x : children[node]) {
            sum += dfs(x, threshold);
        }

        sum = max(sum, -1);
        sum = min(sum, 1);

        return sum;
    };

    int lo = 0, hi = n - 1;
    while (lo < hi) {
        int mid = (lo + hi)/2;

        // cout << mid << lo << hi << endl;

        if (dfs(0, mid) >= 0) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }

    cout << lo + 1 << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; ++t){
        // cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}