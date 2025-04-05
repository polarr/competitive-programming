/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-04-04
 * Contest: Codeforces 2092
 * Problem: E
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

/** 
 * ALGORITHM: Modular Exponentiation 
 * PURPOSE: Computes x^n (mod m)
 * CONSTRAINT: m * m <= LLONG_MAX to prevent overflow
 * TIME: O(log n)
*/
ll mod_exp(ll x, ll n, ll m) {
	x %= m;

	ll res = 1;
	while (n > 0) {
		if (n % 2 == 1) { res = res * x % m; }
		x = x * x % m;
		n /= 2;
	}

	return res;
}

void solve(){
    ll n, m, k; cin >> n >> m >> k;

    ll count = n * m;

    vector<pii> cells;

    map<pii, int> grid;

    rep(i, 0, (int)k){
        int x, y, c; cin >> x >> y >> c;
        grid[{x, y}] = c;
        cells.pb({x, y});
    }

    ll total = 0;
    ll inter = 0;
    ll perim = 0;

    rep(i, 0, (int)k){
        pii cell = cells[i];
        bool edge = false;
        if (cell.first != 1){
            pii left = {cell.first - 1, cell.second};
            if (grid.contains(left)){
                inter += (grid[cell] != grid[left]);
            } else {
                total += grid[cell];
            }
        } else {
            edge = !edge;
        }
        if (cell.first != n){
            pii right = {cell.first + 1, cell.second};
            if (grid.contains(right)){
                inter += (grid[cell] != grid[right]);
            } else {
                total += grid[cell];
            }
        } else {
            edge = !edge;
        }
        if (cell.second != 1){
            pii up = {cell.first, cell.second - 1};
            if (grid.contains(up)){
                inter += (grid[cell] != grid[up]);
            } else {
                total += grid[cell];
            }
        } else {
            edge = !edge;
        }
        if (cell.second != m){
            pii down = {cell.first, cell.second + 1};
            if (grid.contains(down)){
                inter += (grid[cell] != grid[down]);
            } else {
                total += grid[cell];
            }
        } else {
            edge = !edge;
        }

        if (edge){
            perim++;
        }
    }

    total += inter/2;

    ll green = count - k;

    if (perim != 2 * n + 2 * m - 8){
        cout << mod_exp(2, green - 1, MOD) << endl;
        return;
    }

    if (total % 2 == 0){
        cout << mod_exp(2, green, MOD) << endl;
    } else {
        cout << 0 << endl;
    }
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