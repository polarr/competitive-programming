/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-12-27
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
    string s; cin >> s;
    int n = sz(s);

    int ans = 0;
    if (s[0] == 'u') {
        ans++;
        s[0] = 's';
    }

    if (s[n - 1] == 'u') {
        ans++;
        s[n - 1] = 's';
    }

    vi arr;
    rep(i, 0, n) {
        if (s[i] == 's') {
            arr.pb(i);
        }
    }

    rep(i, 0, sz(arr) - 1) {
        int d = arr[i + 1] - arr[i] - 1;

        ans += d/2;
    }

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