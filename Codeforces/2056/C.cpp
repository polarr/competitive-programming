/**
 * Solution by 1egend (polarity.sh)
 * Date: 2025-02-01
 * Contest: Codeforces 2056
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

    if (n == 6){
        cout << "1 1 2 3 1 2" << endl;
        return;
    }

    if (n == 7){
        cout << "1 2 1 1 2 2 2" << endl;
        return;
    }

    if (n == 8){
        cout << "3 3 3 7 3 7 7 3" << endl;
        return;
    }

    if (n == 9){
        cout << "7 3 3 7 5 3 7 7 3" << endl;
        return;
    }

    if (n == 10){
        cout << "7 3 3 7 5 3 7 7 3 8" << endl;
        return;
    }

    int mx = (n - 1)/3 + 1;
    int rem = n - 3 * (mx - 1) - 1;
    vi ans(n);
    rep(i, 0, rem){
        ans[i] = mx;
    }

    rep(i, rem, n - mx){
        int ii = i - rem;
        ans[i] = mx - ii/2;
    }

    rep(i, n - mx, n){
        ans[i] = i - n + mx + 1;
    }

    rep(i, 0, n){
        cout << ans[i] << " ";
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