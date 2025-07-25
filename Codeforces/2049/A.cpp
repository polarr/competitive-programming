/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-06-10
 * Contest: Codeforces 2049
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

    int l = 0;
    int ans = 0;
    rep(i, 0, n){
        if (a[i] == 0){
            if (l > 0){
                ans++;
            }

            l = 0;
            continue;
        }

        l++;
    }

    if (l > 0){
        ans++;
    }

    cout << min(ans, 2) << endl;
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