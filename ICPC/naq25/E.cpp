#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define pb push_back
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

void solve() {
    int rounds = 10;

    ll bx = 144, by = 84;

    auto dist = [&](ll x, ll y) -> ll {
        ll dx = x - bx;
        ll dy = y - by;
        return dx * dx + dy * dy;
    };

    ll ansRed = 0, ansYellow = 0;

    rep(i, 0, rounds){
        ll mnRed = LLONG_MAX, mnYellow = LLONG_MAX;
        int n; cin >> n;
        vector<pll> red(n);
        rep(j, 0, n){
            ll x, y; cin >> x >> y;
            red[j] = {x, y};
            mnRed = min(mnRed, dist(x, y));
        }

        int m; cin >> m;
        vector<pll> yellow(m);
        rep(j, 0, m){
            ll x, y; cin >> x >> y;
            yellow[j] = {x, y};
            mnYellow = min(mnYellow, dist(x, y));
        }

        if (mnRed < mnYellow){
            // red wins
            rep(j, 0, n){
                ll x = red[j].first, y = red[j].second;
                ll d = dist(x, y);
                if (d < mnYellow){
                    ansRed++;
                }
            }
        } else {
            // yellow wins
            rep(j, 0, m){
                ll x = yellow[j].first, y = yellow[j].second;
                ll d = dist(x, y);
                if (d < mnRed){
                    ansYellow++;
                }
            }
        }
    }

    cout << ansRed << " " << ansYellow << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
}