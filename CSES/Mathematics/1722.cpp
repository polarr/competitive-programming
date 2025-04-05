/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-04-04
 * Contest: CSES Problemset
 * Problem: 1722
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

    if (n == 0){
        cout << 0 << endl;
        return;
    }

    n--;

    using Mat2 = array<ll, 4>;

    Mat2 s = {1, 0, 0, 1};
    Mat2 m = {1, 1, 1, 0};

    vl a;

    while (n != 0){
        a.pb(n % 2);
        n /= 2;
    }

    function<Mat2(Mat2, Mat2)> mult;

    mult = [&](Mat2 x, Mat2 y){
        return Mat2{(x[0] * y[0] + x[1] * y[2]) % MOD, (x[0] * y[1] + x[1] * y[3]) % MOD, (x[2] * y[0] + x[3] * y[2]) % MOD, (x[2] * y[1] + x[3] * y[3]) % MOD};
    };

    reverse(all(a));
    rep(i, 0, a.size()){
        s = mult(s, s);
        if (a[i] == 1){
            s = mult(m, s);
        }
    }

    cout << s[0] << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}