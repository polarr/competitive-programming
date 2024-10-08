/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-10-05
 * Contest: ICPC NAQ 2024
 * Problem: H
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

void solve(){
    double x1, y1, x2, y2, a; cin >> x1 >> y1 >> x2 >> y2 >> a;
    double cx = (x1 + x2)/2.0, cy = (y1 + y2)/2.0;

    if (x1 == x2 && y1 == y2){
        cout << fixed << setprecision(25) << cx - a/2.0 << " " << cy - a/2.0 << " " << cx + a/2.0 << " " << cy + a/2.0;
        return;
    }

    double d = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));

    double r1 = a/2.0; double r2 = sqrt(a * a - d * d)/2.0;

    double r1x = (x2 - x1) * r1/d, r1y = (y2 - y1) * r1/d;
    double r2x = r1y * r2/r1; double r2y = - r1x * r2/r1;

    double w = sqrt(r1x * r1x + r2x * r2x);
    double h = sqrt(r1y * r1y + r2y * r2y);

    cout << fixed << setprecision(25) << cx - w << " " << cy - h << " " << cx + w << " " << cy + h;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}