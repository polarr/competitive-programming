/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-09-21
 * Contest: Project Euler
 * Problem: 91
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
    function<int(int, int, int, int)> dot;
    dot = [&](int x1, int y1, int x2, int y2){
        return x1 * x2 + y1 * y2;
    };

    rep(x1, 0, 51){
        rep(y1, 0, 51){
            rep(x2, 0, 51){
                rep(y2, 0, 51){
                    int dx = x1 - x2, dy = y1 - y2;
                    if (x1 == 0 && y1 == 0) continue;
                    if (x2 == 0 && y2 == 0) continue;
                    if (dx == 0 && dy == 0) continue;
                    if (dot(x1, y1, x2, y2) == 0 || dot(x1, y1, dx, dy) == 0 || dot(x2, y2, dx, dy) == 0){
                        ans++;
                    }
                }
            }
        }
    }

    cout << ans/2 << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}