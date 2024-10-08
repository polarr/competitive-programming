/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-10-05
 * Contest: ICPC NAQ 2024
 * Problem: B
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

void solve(){
    int n; cin >> n;

    double ans = 101;
    for (int i = 0; i < n; i++){
        double x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        if (x1 == x2 || x1 * x2 > 0){
            continue;
        }

        double m = (y2 - y1)/(x2 - x1);
        double y0 = y1 - m * x1;

        if (y0 <= 0){
            continue;
        }

        ans = min(ans, y0);
    }

    if (ans == 101){
        cout << fixed << setprecision(1) << -1.0 << endl;
        return;
    }

    cout << fixed << setprecision(10) << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}