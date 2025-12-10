/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-12-09
 * Contest: 
 * Problem: 1725
**/

#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;
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
    int n, a, b; cin >> n >> a >> b;

    vector<ld> arr(7, 1.0/6);
    arr[0] = 0;

    vector<ld> curr = {1};
    auto mult = [&](vector<ld> a, vector<ld> b) -> vector<ld> {
        vector<ld> ans(sz(a) + sz(b) - 1, 0);
        rep(i, 0, sz(a)) {
            rep(j, 0, sz(b)) {
                ans[i + j] += a[i] * b[j];
            }
        }

        return ans;
    };

    rep(i, 0, n) {
        curr = mult(curr, arr);
    }

    ld prob = 0;
    rep(i, a, b + 1) {
        prob += curr[i];
    }

    cout << fixed << setprecision(6) << prob << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}