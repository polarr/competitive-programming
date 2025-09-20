/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-09-14
 * Contest: Project Euler
 * Problem: 100
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
    /**
     * X^2 - 2Y^2 = -1 negative Pell's equation is iff
     * where X = 2x - 1 and Y = 2y - 1 is total number
     * and number of blue discs respectively.
     * 
     * The solutions to this are (1 - sqrt(2))^odd = X - Ysqrt(2)
     */
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}