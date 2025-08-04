/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-08-02
 * Contest: CSES Problemset
 * Problem: 3399
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
    if (a + b > n || (a == 0 ^ b == 0)) {
        cout << "NO" << endl;
        return;
    }

    vi p1, p2;

    rep(i, 0, n){
        p1.pb(i);
        p2.pb(i);
    }

    cout << "YES" << endl;

    rotate(p2.begin() + n - a - b, p2.begin() + n - b, p2.end());

    for (int card : p1){
        cout << card + 1 << " ";
    }

    cout << endl;

    for (int card : p2){
        cout << card + 1 << " ";
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