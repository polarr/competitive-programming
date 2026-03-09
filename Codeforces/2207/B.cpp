/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2026-03-08
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
    int n, m, l; cin >> n >> m >> l;

    vi arr(m, 0);

    vi shine(l, 0);
    rep(i, 0, n) {
        int x; cin >> x;
        --x;
        shine[x] = 1;
    }

    int curr = n;

    rep(i, 0, l) {
        sort(all(arr));
        int change = max(0, m - 1 - curr);
        arr[change]++;
        sort(all(arr));
        if (shine[i]) {
            arr.back() = 0;
            curr--;
        }
    }

    int ans = *max_element(all(arr));
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