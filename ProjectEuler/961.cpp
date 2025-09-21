/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-09-21
 * Contest: Project Euler
 * Problem: 961
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

const int MAX_N = 18;
const ll MOD = 1e9 + 7;

void solve(){
    vector<bool> win((1 << MAX_N), false);
    win[1] = true;
    ll ans = 9;

    vl pow9(MAX_N, 1);
    rep(i, 1, MAX_N){
        pow9[i] = pow9[i - 1] * 9;
    }

    rep(i, 2, 1 << MAX_N){
        bool canWin = false;
        int curr = 0;
        rep(j, 0, MAX_N){
            int nw = i - curr;

            if (i & (1 << j)){
                nw -= 1 << j;
                nw /= 2;
                nw += curr;
                curr += 1 << j;
            } else {
                nw /= 2;
                nw += curr;
            }

            if (nw == i) break;
            if (!win[nw]){
                canWin = true;
                break;
            }
        }

        win[i] = canWin;

        if (canWin){
            ans += pow9[__builtin_popcount(i)];
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