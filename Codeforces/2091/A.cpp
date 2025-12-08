/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-12-07
 * Contest: Codeforces 2091
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
    vi cnt(10, 0);
    int ans = 0;
    rep(i, 0, n) {
        int x; cin >> x;
        cnt[x]++;
        if(cnt[0] >= 3 && cnt[1] >= 1 && cnt[3] >= 1 && cnt[5] >= 1 && cnt[2] >= 2) {
            if (ans == 0) {
                ans = i + 1;
            }
        }
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