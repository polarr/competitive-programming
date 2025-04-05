/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-04-04
 * Contest: Codeforces 2092
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

    string a, b; cin >> a >> b;
    int odd = 0, o = 0;
    int even = 0, e = 0;

    rep(i, 0, n){
        if (i % 2 == 0){
            even++;
            e += 1 - (a[i] - '0');
            o += 1 - (b[i] - '0');
            continue;
        }

        odd++;
        o += 1 - (a[i] - '0');
        e += 1 - (b[i] - '0');
    }

    if (e >= even && o >= odd){
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