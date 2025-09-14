/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-09-14
 * Contest: Project Euler
 * Problem: 4
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
    int ans = 0;
    rep(a, 100, 1000){
        rep(b, 100, 1000){
            int c = a * b;
            vi digits;
            while (c > 0){
                digits.pb(c % 10);
                c /= 10;
            }

            bool pal = true;
            rep(i, 0, sz(digits)){
                if (digits[i] != digits[sz(digits) - i - 1]){
                    pal = false;
                    break;
                }
            }

            if (pal){
                ans = max(ans, a * b);
            }
        }
    }

    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}