/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-07-06
 * Contest: 
 * Problem: C
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
    int n; cin >> n;
    vi brr(n);
    rep(i, 0, n) cin >> brr[i];

    int x = 1;

    for (int i = n - 2; i >= 0; i--){
        if ((brr[i + 1] % brr[i]) != 0){
            x = lcm(x, brr[i]/gcd(brr[i], brr[i + 1]));
        }
    }

    cout << x << endl;
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