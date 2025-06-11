/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-06-10
 * Contest: Codeforces 2049
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

int query(int l, int r){
    cout << "? " << l << " " << r << endl;
    int ans; cin >> ans;
    if (ans == -1){
        throw runtime_error("WA");
    }
    return ans;
}

void solve(){
    int n; cin >> n;
    int nn = n;

    int pw = 0;
    while (nn > 1){
        nn /= 2;
        pw++;
    }

    int quad = 1 << (pw - 2);
    int a = query(1, quad);
    int b = query(quad + 1, 2 * quad);
    int l = 1, r = 2 * quad;
    int type = 0;

    if (a != b){
        l = 2 * quad + 1, r = 4 * quad;
    }

    vi cache(31, -1);
    cache[pw - 1] = query(l, r);
    cache[0] = query(r, r);

    int cmp = 1 - cache[0];
    int pl = 0, pr = 0;

    if (cache[pw - 1] == cache[0]){
        // k > 2 * quad
        if (l == 1){
            type = 1;
        }

        cmp = cache[0];

        l = 2 * quad + 1;
        r = 4 * quad;
    } else {
        // k <= 2 * quad
        if (l == 2 * quad + 1) {
            pl = pr = 2 * quad;
        }

        l = 1;
        r = 2 * quad;
    }

    while (l < r){
        int mid = (l + r)/2;
        int good;
        if (type == 1){
            good = query(n + 1 - mid, n);
        } else {
            good = query(pl + 1, pr + mid);
        }

        if (good == cmp){
            r = mid;
        } else {
            l = mid + 1;
        }
    }

    cout << "! " << l << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for (int t = 1; t <= tc; ++t){
        // cout << "Case #" << t << ": ";
        try {
            solve();
        } catch (const std::exception& e){
            break;
        }
    }
    return 0;
}