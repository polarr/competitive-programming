/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-05-17
 * Contest: Codeforces 2109
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
    int n, m, a, b; cin >> n >> m >> a >> b;

    int nn = n, mm = m;

    int ans = 1;
    n = min(a, n - a + 1);

    while (n > 1){
        n = (n + 1)/2;
        ans++;
    }

    while (m > 1){
        m = (m + 1)/2;
        ans++;
    }

    int ans2 = 1;
    n = nn; m = mm;
    m = min(b, m - b + 1);

    while (n > 1){
        n = (n + 1)/2;
        ans2++;
    }

    while (m > 1){
        m = (m + 1)/2;
        ans2++;
    }

    cout << min(ans, ans2) << endl;
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