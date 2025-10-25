/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-10-22
 * Contest: Project Euler
 * Problem: 101
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

using ld = long double;
using pdd = pair<ld, ld>;

ld calc(ld x){
    return (pow(x, 11) + 1)/(x + 1);
}

void solve(){
    vector<ld> c(12);
    rep(i, 1, 12){
        c[i] = calc(i);
    }

    auto interpolate = [&](int idx, ld x) -> ld {
        ld ret = 0;
        rep(i, 1, idx + 1){
            ld curr = c[i];
            rep(j, 1, idx + 1){
                if (j == i) continue;
                curr *= (x - j);
                curr /= ((ld)i - j);
            }

            ret += curr;
        }

        return ret;
    };

    ld ans = 0;

    ld epsilon = 0.001;

    rep(idx, 1, 11){
        rep(i, idx + 1, 12){
            ld pred = interpolate(idx, i);
            if (abs(pred - c[i]) > epsilon){
                ans += round(pred);
                break;
            }
        }
    }

    cout << fixed << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}