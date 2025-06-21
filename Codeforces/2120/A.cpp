/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-06-21
 * Contest: 
 * Problem: A
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
    int a, b, c, d, e, f; cin >> a >> b >> c >> d >> e >> f;
    if (a < b){
        if (b - a == c && b - a == e && d + f == b){
            cout << "YES" << endl;
            return;
        }

        if (b - a == c + e && d == b && f == b){
            cout << "YES" << endl;
            return;
        }
    } else if (b < a){
        if (a - b == d && a - b == f && c + e == a){
            cout << "YES" << endl;
            return;
        }

        if (a - b == d + f && c == a && e == a){
            cout << "YES" << endl;
            return;
        }
    }

    cout << "NO" << endl;
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