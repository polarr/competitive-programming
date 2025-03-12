/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-03-11
 * Contest: DMOJ
 * Problem: pies
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

const int MAX_N = 3e5 + 1;
const ll MOD = 1e9 + 7;

vector<long double> coeff = {0, -1.0/12, 1.0/120, -1.0/252, 1.0/240, -5.0/660, 691.0/32760, -1.0/12};

long double digamma(long double x){
    if (x < 5){
        return digamma(x + 1) - 1.0/x;
    }

    long double ans = log(x) - 1.0/(2 * x);
    long double xi = 1;
    rep(i, 1, 4){
        xi /= x;
        xi /= x;
        ans += coeff[i] * xi;
    }

    return ans;
}

void solve(){
    int x, y, z; cin >> x >> y >> z;

    long double s = x + y;
    long double c = (long double)(x - y);

    cout << fixed << setprecision(10);

    cout << c/(2 * z) * (digamma((s + z)/(2 * z)) - digamma(s/(2 * z))) << endl;
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