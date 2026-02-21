/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2026-02-20
 * Contest: 
 * Problem: E
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
    string s; cin >> s;

    vi arr(n);
    rep(i, 0, n) arr[i] = s[i] - '0';

    int o = 0, z = 0;
    rep(i, 0, n) {
        if (arr[i] == 0) {
            z++;
        } else {
            o++;
        }
    }

    if (o == 0) {
        cout << -1 << endl;
        return;
    }


    if (n == 1) {
        cout << 0 << endl;
        return;
    }

    if (o >= z) {
        cout << n << endl;
        return;
    }

    vi pre(n + 1, 0);
    rep(i, 0, n) {
        pre[i + 1] = pre[i] + (arr[i] == 1 ? 1 : -1);
    }

    int d = z - o;
    if (d == 1) {
        cout << n + 1 << endl;
        return;
    }

    int mx = 0;
    rep(i, 1, n + 1) {
        if (mx >= d + pre[i] + 1) {
            cout << n + 1 << endl;
            return;
        }
        
        mx = max(mx, pre[i]);
    }

    rep(i, 1, n) {
        if (arr[i] == 1 && arr[i - 1] == 1) {
            cout << n + 2 << endl;
            return;
        }
    }

    rep(i, 0, n) {
        if (pre[i + 1] >= 0) {
            cout << n + 2 << endl;
            return;
        }

        if (pre[n] - pre[i] >= 0) {
            cout << n + 2 << endl;
            return;
        }
    }

    cout << n + 3 << endl;
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