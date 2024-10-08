/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-10-05
 * Contest: ICPC NAQ 2024
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
    int l; cin >> l;
    ull x1, x2, y1, y2, z1, z2; cin >> x1 >> x2 >> y1 >> y2 >> z1 >> z2;

    while (l > 0){
        bool x = ((x2 < 3 * x1) && (3 * x1 < 2 * x2));
        bool y = ((y2 < 3 * y1) && (3 * y1 < 2 * y2));
        bool z = ((z2 < 3 * z1) && (3 * z1 < 2 * z2));


        if (x && y || y && z || z && x){
            cout << 0 << endl;
            return;
        }

        x1 = (3 * x1) % x2;
        y1 = (3 * y1) % y2;
        z1 = (3 * z1) % z2;

        l--;
    }

    cout << 1 << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}