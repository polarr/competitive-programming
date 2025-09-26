/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-09-25
 * Contest: 
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
    ll h, d; cin >> h >> d;

    ll lo = 0, hi = d;
    while (lo < hi){
        ll mid = (lo + hi)/2;

        ll k = mid + 1;
        ll t = d/k;
        ll r = d % k;
        ll total = (t * (t + 1))/2 * (k - r);
        total += ((t + 1) * (t + 2))/2 * r;

        if (total < h + mid){
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }

    cout << d + lo << endl;
    cerr << endl;
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