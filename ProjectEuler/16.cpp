/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-09-21
 * Contest: Project Euler
 * Problem: 16
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
    vi digits(400, 0);
    digits[0] = 1;
    rep(i, 0, 1000){
        for (int j = digits.size() - 1; j >= 0; j--){
            int d = digits[j];
            d *= 2;
            if (d >= 10){
                d -= 10;
                digits[j + 1]++;
            }
            digits[j] = d;
        }
    }

    int ans = 0;

    rep(i, 0, digits.size()){
        ans += digits[i];
    }

    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}