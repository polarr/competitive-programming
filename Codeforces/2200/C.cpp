/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2026-03-02
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

    queue<int> q;
    string s; cin >> s;
    vi arr(n);
    rep(i, 0, n) {
        int x = s[i] - 'a';
        arr[i] = x;
    }

    while (sz(arr) > 0) {
        vi brr;
        rep(i, 0, sz(arr)) {
            if (i != sz(arr) - 1 && arr[i] == arr[i + 1]) {
                i++;
                continue;
            }

            brr.pb(arr[i]);
        }

        if (sz(brr) == sz(arr)) {
            cout << "NO" << endl;
            return;
        }

        arr = brr;
    }

    cout << "YES" << endl;
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