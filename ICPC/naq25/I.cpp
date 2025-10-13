#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using ld = long double;
#define pb push_back
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

void solve() {
    cout << fixed << setprecision(20);
    int n; cin >> n;
    vl team(n), person(n);
    rep(i, 0, n) cin >> team[i];
    rep(i, 0, n) cin >> person[i];

    sort(all(person));
    reverse(all(person));

    ld ans = 0;
    ld solve = 0;
    rep(i, 0, n){
        solve += person[i];
        ld sizeSolve = solve + team[i];
        ld cnt = i + 1;

        ans = max(ans, sizeSolve/cnt);
    }   

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
}