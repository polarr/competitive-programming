/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-05-17
 * Contest: Codeforces 2109
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
    int n; cin >> n;
    vi a(n);
    rep(i, 0, n){
        cin >> a[i];
    }

    int cnt = 0;

    rep(i, 0, n){
        if (i < n - 1 && a[i] == 0 && a[i + 1] == 0){
            cout << "YES" << endl;
            return;
        }

        if (a[i] == 1){
            cnt++;
        }
    }

    if (cnt == n){
        cout << "YES" << endl;
        return;
    }

    cout << "NO" << endl;
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