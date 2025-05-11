/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-05-10
 * Contest: Codeforces 2007
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
    int n, a, b; cin >> n >> a >> b;
    int g = gcd(a, b);
    int mn = g, mx = 0;
    vi possible;
    rep(i, 0, n){
        int x; cin >> x;
        possible.pb(x % g);
    }

    sort(all(possible));
    int ans = possible[n - 1] - possible[0];
    rep(i, 1, n){
        if (possible[i] != possible[i - 1]){
            ans = min(ans, possible[i - 1] + g - possible[i]);
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