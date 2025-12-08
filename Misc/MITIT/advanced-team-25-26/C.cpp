/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-12-07
 * Contest: 
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
    int n, b; cin >> n >> b;

    ll sum = 0;
    vi arr(n);
    rep(i, 0, n) {
        cin >> arr[i];
        sum += arr[i];
    }

    if ((sum % (b - 1)) != 0) {
        cout << "NO" << endl;
        return;
    }

    vi x = {0}, y = {0};
    rep(i, 0, n) {
        int a = arr[i];
        int py = y[i];
        x.pb(py);
        int ny = a + py;
        if (ny >= b) {
            x[i + 1]++;
            y[i]++;
            ny++;
            ny %= b;
        }

        y.pb(ny);
    }

    if (y.back() != 0){
        int d = b - y.back();
        y[sz(y) - 1] += d;
        x[sz(x) - 1] += d;
    }

    for (int i = sz(x) - 1; i >= 0; i--) {
        if (x[i] >= b) {
            x[i] %= b;
            x[i - 1]++;
        }
    }

    for (int i = sz(y) - 1; i >= 0; i--) {
        if (y[i] >= b) {
            y[i] %= b;
            y[i - 1]++;
        }
    }

    cout << "YES" << endl;
    cout << sz(x) + 1 << endl;
    cout << 1 << " ";
    rep(i, 0, sz(x)) {
        cout << x[i] << " ";
    }
    cout << endl;
    cout << 1 << " ";
    rep(i, 0, sz(y)) {
        cout << y[i] << " ";
    }
    cout << endl;
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