/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-06-22
 * Contest: Codeforces 2075
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
    int n, k; cin >> n >> k;

    int mxo = k;
    int mxe = k;

    if (k % 2 == 0){
        mxo = k - 1;
    } else {
        mxe = k - 1;
    }

    int ans = 0;
    if (n % 2 == 1){
        n -= mxo;
        ans++;
    }

    ans += (n + mxe - 1)/mxe;

    cout << ans << endl;
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