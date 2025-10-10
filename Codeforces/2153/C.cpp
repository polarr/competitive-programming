/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-10-10
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
    int n; cin >> n;
    vl arr(n);
    rep(i, 0, n){
        cin >> arr[i];
    }

    sort(all(arr));
    vl brr;
    int cnt = 0;
    ll sum = 0;
    rep(i, 0, n){
        if (i != n - 1 && arr[i] == arr[i + 1]){
            cnt += 2;
            sum += 2LL * arr[i];
            i++;
        } else {
            brr.pb(arr[i]);
        }
    }

    sort(all(brr));
    for (int i = sz(brr) - 1; i >= 0; i--){
        ll len = brr[i];
        if (i != 0){
            len = brr[i] - brr[i - 1];
        }

        if (len >= sum){
            continue;
        }

        sum += brr[i];
        cnt++;
        if (i != 0){
            sum += brr[i - 1];
            cnt++;
        }
        break;
    }

    if (cnt <= 2){
        cout << 0 << endl;
        return;
    }

    cout << sum << endl;
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