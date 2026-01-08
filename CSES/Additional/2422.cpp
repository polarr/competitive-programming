/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2026-01-07
 * Contest: CSES Problemset
 * Problem: 2422
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
    ll n; cin >> n;

    ll want = n * n / 2 + 1;

    ll lo = 1, hi = n * n;

    auto count = [&](ll mid) -> ll {
        ll leq = 0;

        for (ll i = 1; i <= n; i++) {
            leq += min(n, mid/i);
        }

        return leq;
    };

    while (lo < hi) {
        ll mid = (lo + hi)/2;
        ll leq = count(mid);

        if (leq >= want) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }

    // vl arr;

    // rep(i, 1, n + 1) {
    //     rep(j, 1, n + 1) {
    //         arr.pb(i * j);
    //     }
    // }

    // sort(all(arr));
    // rep(i, sz(arr)/2 - 5, sz(arr)/2 + 5) {
    //     cout << arr[i] << " ";
    // }

    cout << lo << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}