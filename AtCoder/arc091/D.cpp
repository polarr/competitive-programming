/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2026-01-11
 * Contest: AtCoder arc091
 * Problem: D
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

int nim(int n, int k) {
    if (k == 1) return n;
    if (n % k == 0) {
        return n/k;
    }

    int r = n/k;
    int rk = r * k;
    r++;
    int t = (n - rk)/r;
    if (t == 0) t++;

    return nim(n - r * t, k);
}

void solve(){
    int n; cin >> n;

    int x = 0;
    rep(i, 0, n) {
        int a, k; cin >> a >> k;
        x ^= nim(a, k);
    }

    if (x == 0) {
        cout << "Aoki" << endl;
    } else {
        cout << "Takahashi" << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}