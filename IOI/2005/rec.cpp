/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2026-01-11
 * Contest: IOI 2005
 * Problem: rec
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

const int MAX_N = 1e8 + 1;
const ll MOD = 1e9 + 7;

int nim(int x) {
    if (x % 2 == 0) {
        return x/2;
    }

    return nim(x/2);
}

void solve(){
    while (true) {
        int w, h; cin >> w >> h;

        if (w == -1) {
            return;
        }

        int x = nim(w), y = nim(h);
        int z;

        if (x >= y) {
            z = 2 * y;
            while (2 * z < w) {
                z = 2 * z + 1;
            }
            cout << "V " << w - z << endl;
        } else {
            z = 2 * x;
            while (2 * z < h) {
                z = 2 * z + 1;
            }
            cout << "H " << h - z << endl;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}