/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-06-17
 * Contest: Codeforces 2121
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

void solve(){
    int n; cin >> n;
    multiset<int> s;
    s.insert(0);
    rep(i, 0, n){
        s.insert(INT_MAX);
    }
    int ans = 0;
    rep(i, 0, n){
        int l, r; cin >> l >> r;
        auto j = s.upper_bound(r);
        if (*j == INT_MAX){
            ans++;
        }
        s.erase(s.upper_bound(r));
        s.insert(l);

        cout << ans << " ";
    }

    cout << endl;
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