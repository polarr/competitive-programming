/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-05-23
 * Contest: 
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
    ll a, b, r; cin >> a >> b >> r;
    ll ans = 0;
    bool found = false;

    vl arr;

    ll curr = 0;

    bool match;

    for (ll i = 59; i >= 0; i--){
        ll k = (1LL << i);
        bool hasA = a & k;
        bool hasB = b & k;

        if (hasA == hasB){
            continue;
        }

        if (found){
            if (hasA != match){
                ans -= k;
                continue;
            }

            arr.pb(k);
            curr += k;
            continue;
        }

        found = true;
        ans = k;
        match = hasA;
    }

    int idx = 0;

    ll res = 0;

    while (curr > r){
        if (res + arr[idx] <= r){
            res += arr[idx];
            idx++;
            continue;
        }
        curr -= arr[idx];
        ans += arr[idx];
        idx++;
    }

    cout << ans - curr << endl;
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