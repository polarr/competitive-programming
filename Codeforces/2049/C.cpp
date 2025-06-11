/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-06-10
 * Contest: Codeforces 2049
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
    int n, x, y; cin >> n >> x >> y;
    --x; --y;

    vi a(n);
    if (n % 2 == 1){
        a[x] = 2;
        rep(i, 1, n){
            if (i % 2 == 1){
                a[(x + i) % n] = 1;
            } else {
                a[(x + i) % n] = 0;
            }
        }
    } else {
        if (abs(y - x) % 2 == 0){
            a[x] = 2;
        } else {
            a[x] = 1;
        }
        rep(i, 1, n){
            if (i % 2 == 1){
                a[(x + i) % n] = 0;
            } else {
                a[(x + i) % n] = 1;
            }
        }
    }

    rep(i, 0, n){
        cout << a[i] << " ";
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