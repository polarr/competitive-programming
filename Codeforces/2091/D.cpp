/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-12-07
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

void solve(){
    ll n, m, k; cin >> n >> m >> k;

    ll lo = 1, hi = m;
    while (lo < hi) {
        ll mid = (lo + hi)/2;

        ll b = mid + 1;
        ll t = m/b;
        ll r = m % b;
        ll p = t * mid + r;

        p *= n;
        if (p >= k) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }

    cout << lo << endl;
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