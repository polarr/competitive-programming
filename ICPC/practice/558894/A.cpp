/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-10-16
 * Contest: ICPC Practice Codeforces 558894
 * Problem: A
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

void solve(){
    int mnx = 1001, mxx = -1001, mny = 1001, mxy = -1001;
    for (int i = 0; i < 4; i++){
        int x, y; cin >> x >> y;

        mnx = min(mnx, x);
        mxx = max(mxx, x);
        mny = min(mny, y);
        mxy = max(mxy, y);
    }

    cout << (mxx - mnx) * (mxy - mny) << endl;
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