/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-12-26
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
    int n, a, q; cin >> n >> a >> q;
    string s; cin >> s;

    int mx = a;
    int tot = a;
    int curr = a;
    rep(i, 0, q) {
        if (s[i] == '+') {
            curr++;
            tot++;
        } else {
            curr--;
        }

        mx = max(curr, mx);
    }

    if (mx == n) {
        cout << "YES" << endl;
        return;
    }

    if (tot < n) {
        cout << "NO" << endl;
        return;
    }

    cout << "MAYBE" << endl;
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