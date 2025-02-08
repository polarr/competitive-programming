/**
 * Solution by 1egend (polarity.sh)
 * Date: 2025-02-07
 * Contest: CEOI 2018
 * Problem: glo
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
    int n, x; cin >> n >> x;
    vi arr(n);
    rep(i, 0, n){
        cin >> arr[i];
    }

    vi dp1(n + 1, INT_MAX);
    vi dp2(n + 1, INT_MAX);
    vi lis(n + 1, 0);

    dp1[0] = -INT_MAX;
    dp2[0] = -INT_MAX;

    for (int i = n - 1; i >= 0; i--){
        int a = arr[i];
        auto j = lower_bound(all(dp2), -a);
        if (j != dp2.end()){
            dp2[j - dp2.begin()] = -a;
            lis[i] = j - dp2.begin();
        }
    }

    int ans = lis[0];

    rep(i, 0, n){
        int a = arr[i];
        auto j = lower_bound(all(dp1), a);
        if (j != dp1.end()){
            dp1[j - dp1.begin()] = a;
        }

        int pref = 0;
        if (i != n - 1){
            int b = arr[i + 1];
            pref = (prev(lower_bound(all(dp1), b + x)) - dp1.begin());
        }
        
        ans = max(ans, pref + lis[i + 1]);
    }

    // cout << lis[4] << endl;

    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}