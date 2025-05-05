/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-05-03
 * Contest: Codeforces 2098
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

    vi a(n);
    rep(i, 0, n){
        cin >> a[i];  
    }

    sort(all(a));

    vector<pii> b;
    int cnt = 1;
    rep(i, 1, n){
        if (a[i] != a[i - 1]){
            b.pb(pii{a[i - 1], cnt});
            cnt = 1;
        } else {
            cnt++;
        }
    }

    b.pb({a[n - 1], cnt});
    int carry = 0;
    for (int i = b.size() - 1; i >= 0; i--){
        pii x = b[i];
        if (i == b.size() - 1 || x.first != b[i + 1].first - 1){
            carry = 0;
        }

        if (carry == 0){
            if (x.second >= 4){
                cout << "YES" << endl;
                return;
            }
            else if (x.second >= 2){
                carry = 1;
            }
        } else {
            // carry == 1
            if (x.second >= 2){
                cout << "YES" << endl;
                return;
            }
        }
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