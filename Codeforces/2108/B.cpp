/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-05-04
 * Contest: Codeforces 2108
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
    int n, x; cin >> n >> x;

    if (n == 1 && x == 0){
        cout << -1 << endl;
        return;
    }

    ll ans = 0;

    int small = -1;
    int cnt = 0;

    rep(i, 0, 32){
        if (x & (1 << i)){
            n--;
            cnt++;
            ans += (1 << i);
        } else {
            if (small == -1) small = i;
        }
    }

    if (n <= 0){
        cout << ans << endl;
        return;
    }

    if (n % 2 == 0){
        cout << ans + n << endl;
    } else {
        ans += n - 1;
        if (cnt > 1 || (cnt == 1 && !(x & 1))){
            ans += 2;
        } else {
            ans += 4;
        }
        cout << ans << endl;
    }
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