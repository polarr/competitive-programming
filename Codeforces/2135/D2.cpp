/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-08-28
 * Contest: Codeforces 2135
 * Problem: D2
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

const int MAX_N = 10000;
const int BLOCK = 120;
const ll MOD = 1e9 + 7;

ll query(vi arr){
    cout << "? " << arr.size();
    rep(i, 0, arr.size()){
        cout << " " << arr[i];
    }
    cout << endl;

    int ans; cin >> ans;
    return ans;
}

vi blocks(MAX_N, BLOCK);
vi ones(BLOCK * BLOCK, 1);

void solve(){
    ll q1 = query(blocks);
    if (q1 == 0){
        ll q2 = query(ones);
        cout << "! " << (BLOCK * BLOCK + q2 - 1)/q2 << endl;
        return;
    }

    int mn = BLOCK * (MAX_N + q1 - 1)/q1, mx = min((int)1e5, BLOCK * (int)((MAX_N + q1 - 2)/(q1 - 1)) - 1);

    vi ask;
    rep(i, 0, mx - mn + 1){
        ask.pb(mn);
        if (i != mx - mn) ask.pb(mx - mn - i);
    }

    ll q2 = query(ask);

    cout << "! " << mx - (q2 - (mx - mn + 1)) << endl;

    // int lo = mn, hi = mx;
    // while (lo < hi){
    //     int mid = (lo + hi)/2;
    //     int lines = 1;
    //     int curr = 0;
    //     for (int el : ask){
    //         if (curr + el > mid){
    //             lines++;
    //             curr = el;
    //         } else {
    //             curr += el;
    //         }
    //     }

    //     if (lines == q2){
    //         cout << "! " << mid << endl;
    //         return;
    //     }

    //     if (lines < q2){
    //         hi = mid - 1;
    //     } else {
    //         lo = mid + 1;
    //     }
    // }
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