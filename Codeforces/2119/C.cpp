/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-07-05
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

const int MX = 59;

void solve(){
    ll n, l, r, k; cin >> n >> l >> r >> k;

    if (l == 0 || (n % 2 == 1)){
        cout << l << endl;
        return;
    }

    if (n == 2){
        cout << -1 << endl;
        return;
    }

    int lsb = -1;
    for (int i = MX; i >= 0; i--){
        if (l & (1LL << i)){
            lsb = i;
            break;
        }
    }

    lsb++;
    if (r < (1LL << lsb)){
        cout << -1 << endl;
        return;
    }

    if (k < n - 1){
        cout << l << endl;
    } else {
        cout << (1LL << lsb) << endl;
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