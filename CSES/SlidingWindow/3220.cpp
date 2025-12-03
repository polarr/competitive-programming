/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-12-02
 * Contest: 
 * Problem: 3220
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
    ll x, a, b, c; cin >> x >> a >> b >> c;
    vl arr(n, x);
    rep(i, 1, n) {
        arr[i] = (arr[i - 1] * a + b) % c;
    }

    ll sum = 0, ans = 0;
    rep(i, 0, k - 1) {
        sum += arr[i];
    }

    rep(i, k - 1, n) {
        sum += arr[i];
        int j = i - k;
        if (j >= 0) {
            sum -= arr[j];
        }

        // cout << sum << endl;

        ans ^= sum;
    }

    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}