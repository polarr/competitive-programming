/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-05-07
 * Contest: CSES Problemset
 * Problem: 1728
**/

#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = __float128;
using vi = vector<int>;
using vl = vector<ll>;
using pii = pair<int, int>;
#define pb push_back
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

// THIS DOES NOT PASS DUE TO PRECISION LIMITS
// INSTEAD, THIS PYTHON DOES (But I don't want to pollute my 100% C++ usage!)
/** 
from decimal import *
import math
n = int(input())

ans = Decimal(0)
r = [int(x) for x in input().split()]

for i in range(n - 1):
    for j in range(i + 1, n):
        a = r[i]
        b = r[j]
        tot = Decimal(0)
        for k in range(2, a + 1):
            tot += min(b, k - 1)
        
        ans += tot / Decimal(a * b)

print("{0:0.6f}".format(round(Decimal(ans * Decimal(1e6)))/Decimal(1e6)))
 */

void solve(){
    int n; cin >> n;

    ld ans = 0;
    vector<int> r(n);
    rep(i, 0, n){
        cin >> r[i];
    }

    rep(i, 0, n - 1){
        ld add = 0;
        rep(j, i + 1, n){
            int a = r[i], b = r[j];
            int tot = 0;
            rep(k, 2, a + 1){
                tot += min(b, k - 1);
            }

            add += (ld) tot / (ld) b;
        }
        add /= (ld) r[i];
        ans += add;
    }

    ld mult = 1e6;

    cout << fixed << setprecision(20) << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}