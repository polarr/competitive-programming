/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-03-07
 * Contest: CSES Problemset
 * Problem: 1097
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
    vl arr(n);
    rep(i, 0, n){
        cin >> arr[i];
    }

    vl p(n + 1, 0);

    rep(i, 0, n){
        p[i + 1] = p[i] + arr[i];
    }

    auto rsum = [&](int i, int j){
        return p[j + 1] - p[i];
    };

    vector<vl> dp(n, vl(n, -LLONG_MAX));

    function<ll(int, int)> r;
    r = [&](int i, int j){
        if (dp[i][j] != -LLONG_MAX){
            return dp[i][j];
        }

        if (i == j){
            return dp[i][j] = arr[i];
        }

        ll a = arr[i] + rsum(i + 1, j) - r(i + 1, j);
        ll b = arr[j] + rsum(i, j - 1) - r(i, j - 1);

        return dp[i][j] = max(a, b);
    };

    cout << r(0, n - 1) << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}