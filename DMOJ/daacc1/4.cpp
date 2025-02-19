/**
 * Solution by 1egend (polarity.sh)
 * Date: 2025-02-15
 * Contest: DMOJ daacc1
 * Problem: 4
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
    int n, k; string s; cin >> n >> k >> s;
    vi a(n + 1, INT_MAX);
    for (int i = n - 1; i >= 0; i--){
        int l = s[i] - '0';

        a[i] = a[i + 1];
        if (l == 1){
            a[i] = i;
        }
    }

    int mx = -INT_MAX;
    int ans = 0;

    rep(i, 0, n){
        if (s[i] - '0' == 1){
            mx = max(mx, i);
        }
        if (mx < i - k && a[i] > i + k){
            ans++;
            mx = i + k;
        }
    }

    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}