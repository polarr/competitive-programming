/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-07-21
 * Contest: 
 * Problem: B
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

    vl mx(n);
    ll curr = -1;
    rep(i, 0, n){
        curr = max(curr, arr[i]);
        mx[i] = curr;
    }

    ll sum = 0;
    rep(i, 0, n){
        if (i == n - 1) cout << sum + arr[0] << " ";
        else cout << sum + max(mx[n - 2 - i], arr[n - 1 - i]) << " ";
        sum += arr[n - 1 - i];
    }

    cout << endl;
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