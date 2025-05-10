/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-05-10
 * Contest: Leetcode
 * Problem: 3537
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
    int p = pow(2, n);

    vector<vector<int>> arr(p, vector<int>(p, 0));

    function<void(int, int, int, int)> r;
    r = [&](int y, int x, int l, int c) {
        if (l == 1){
            arr[y][x] = c;
            return;
        }

        int ll = l/2;
        int d = ll * ll;

        r(y, x + ll, ll, c);
        r(y + ll, x + ll, ll, c + d);
        r(y + ll, x, ll, c + 2 * d);
        r(y, x, ll, c + 3 * d);
    };

    r(0, 0, p, 0);

    for (int i = 0; i < p; i++){
        for (int j = 0; j < p; j++){
            cout << arr[i][j] << " ";
        }
    }

    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}