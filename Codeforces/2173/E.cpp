/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-12-05
 * Contest: 2173
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

void solve(){
    int n; cin >> n;
    vi pos(n), arr(n);
    rep(i, 0, n) {
        int x; cin >> x;
        --x;
        arr[i] = x;
        pos[x] = i;
    }

    function<int(int, int)> swap1;
    function<void(int, int)> swap2;
    swap1 = [&](int i, int j) {
        if (i == j) return 0;
        cout << "? " << i + 1 << " " << j + 1 << endl;
        int a, b; cin >> a >> b;
        --a; --b;
        int u = arr[a], v = arr[b];
        swap(pos[u], pos[v]);
        swap(arr[a], arr[b]);

        if ((a == i && b == j) || (a == j && b == i)) {
            return 0;
        }

        return 1 + swap1(i, j);
    };

    swap2 = [&](int i, int j) {
        if (i == j) return;
        int x = swap1(i, j);
        if (x % 2 == 1) {
            swap2(n - 1 - i, n - 1 - j);
        }
    };

    for (int i = (n - 1)/2; i >= 0; i--) {
        swap1(i, pos[i]);

        int j = n - 1 - i;
        if (j != i) {
            swap2(j, pos[j]);
        }
    }

    cout << "!" << endl;
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