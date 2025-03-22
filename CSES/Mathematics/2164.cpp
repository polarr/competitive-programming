/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-03-21
 * Contest: CSES Problemset
 * Problem: 2164
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
    int q; cin >> q;

    function<int(int, int)> r;

    r = [&](int n, int k){
        if (n == 1){
            return 1;
        }

        if (2 * k <= n){
            return 2 * k;
        }

        int nn = n/2;
        int nx = r(n - nn, k - nn);

        if (n % 2 == 0){
            return nx * 2 - 1;
        }

        if (nx == 1){
            return n;
        }

        return (nx - 1) * 2 - 1;
    };

    rep(i, 0, q){
        int n, k; cin >> n >> k;

        cout << r(n, k) << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}