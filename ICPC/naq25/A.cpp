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

void solve() {
    int r, g, b; cin >> r >> g >> b;
    int cr, cg, cb; cin >> cr >> cg >> cb;
    int rg, gb; cin >> rg >> gb;
    
    r = max(0, r - cr);
    g = max(0, g - cg);
    b = max(0, b - cb);

    if (rg < r){
        cout << -1 << endl;
        return;
    }

    if (gb < b){
        cout << -1 << endl;
        return;
    }

    int ans = 0;
    ans += r;
    ans += b;
    rg -= r;
    gb -= b;

    if (g > 0){
        if (g > rg + gb){
            cout << -1 << endl;
            return;
        }

        ans += g;
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
}