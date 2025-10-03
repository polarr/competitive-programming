/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-10-02
 * Contest: Codeforces 2029
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
    string s; cin >> s;
    int zero = 0, one = 0;
    rep(i, 0, n){
        if (s[i] == '0'){
            zero++;
        } else {
            one++;
        }
    }

    string r; cin >> r;
    rep(i, 0, n - 1){
        if (zero == 0 || one == 0){
            cout << "NO" << endl;
            return;
        }

        if (r[i] == '1'){
            zero--;
        } else {
            one--;
        }
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