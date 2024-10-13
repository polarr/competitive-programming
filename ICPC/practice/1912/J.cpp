/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-10-12
 * Contest: ICPC Practice Codeforces 1912
 * Problem: J
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

void solve(){
    int t, s; cin >> t >> s;

    if (s == 1){
        int x; cin >> x;
        if (t % x == 0){
            cout << 1 << endl;
        } else {
            cout << 0 << endl;
        }
        return;
    }

    if (s == 2){
        int x, y; cin >> x >> y;
        int l = lcm(x, y);

        int lx = l/x, ly = l/y;

        ull ans = 0;

        int p = t/l;
        int r = t % l;

        for (int rx = 0; rx < lx; rx++){
            for (int ry = 0; ry < ly; ry++){
                int actual = x * rx + y * ry;
                if (actual > t || actual % l != r){
                    continue;
                }

                ull pp = p - actual/l;
                ans += pp + 1;
            }
        }

        cout << ans << endl;
        return;
    }

    if (s == 3){
        int x, y, z; cin >> x >> y >> z;
        int l = lcm(lcm(x, y), z);

        int lx = l/x, ly = l/y, lz = l/z;

        ull ans = 0;

        int p = t/l;
        int r = t % l;

        for (int rx = 0; rx < lx; rx++){
            for (int ry = 0; ry < ly; ry++){
                int zrz = (2 * l + r - x * rx - y * ry) % l;
                int actual = x * rx + y * ry + zrz;
                if (actual > t || zrz % z != 0){
                    continue;
                }

                ull pp = p - actual/l;
                ans += (pp + 2) * (pp + 1)/2;
            }
        }

        cout << ans << endl;
    }
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