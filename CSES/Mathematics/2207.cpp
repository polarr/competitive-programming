/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-12-09
 * Contest: 
 * Problem: 2207
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

const int MAX_N = 1223;
const ll MOD = 1e9 + 7;

vi ans(MAX_N, 0);

void solve(){
    int n; cin >> n;

    bool good = true;
    if (n < MAX_N) {
        good = (ans[n] != 0);
    }

    if (good) {
        cout << "first\n";
        return;
    }

    cout << "second\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    rep(i, 2, MAX_N) {
        vi mex(50, false);
        rep(j, 1, (i + 1)/2) {
            int k = ans[j] ^ ans[i - j];
            mex[k] = true;
        }

        rep(j, 0, MAX_N) {
            if (!mex[j]) {
                ans[i] = j;
                break;
            }
        }
    }

    int tc;
    cin >> tc;
    for (int t = 1; t <= tc; ++t){
        // cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}