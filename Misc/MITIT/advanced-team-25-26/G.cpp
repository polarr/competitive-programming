/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-12-07
 * Contest: 
 * Problem: F
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
const int INF = 1e8;

void solve(){
    int n, q; cin >> n >> q;

    int rt = sqrt(n);
    int k = (n - 1)/rt + 1;

    using T = array<int, 5>;
    vector<T> block(k);

    vi arr(n);
    rep(i, 0, n){
        cin >> arr[i];
    }

    auto calc = [&](int i) {
        int b = i/rt;
        int l = b * rt;
        int r = min(n, l + rt);
        int sum = 0;
        int mxp = -INF;
        int mnp = INF;
        int mxs = -INF;
        int mns = INF;
        rep(j, l, r) {
            sum += arr[j];
            mxp = max(mxp, sum);
            mnp = min(mnp, sum);
        }
        sum = 0;
        for (int j = r - 1; j >= l; j--) {
            sum += arr[j];
            mxs = max(mxs, sum);
            mns = min(mns, sum);
        }

        block[b] = {sum, mxp, mnp, mxs, mns};
    };

    rep(i, 0, k) {
        calc(i);
    }

    vi pre(n + 1, 0);
    rep(i, 0, n) {
        pre[i + 1] = pre[i] + arr[i];
    }

    rep(qq, 0, q) {
        int c; cin >> c;
        if (c == 1) {
            int j, x; cin >> j >> x;
            --j;
            arr[j] = x;
            calc(j);
            continue;
        }

        int x; cin >> x;
        int mx = -INF, mn = INF;
        int mxs = 0, mns = 0;
        
        rep(i, 0, k) {
            //block[b] = {sum, mxp, mnp, mxs, mns};
            mx = max(mx, mxs + block[i][1]);
            mn = min(mn, mns + block[i][2]);
            mxs = max(mxs + block[i][0], max(0, block[i][3]));
            mns = min(mns + block[i][0], min(0, block[i][4]));
        }

        bool found = (x < 0 && mn <= x) || (x > 0 && mx >= x);
        if (!found) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            cout << 1 << " " << 1 << "\n";
        }
    }

    // rep(qq, 0, q) {
    //     int c; cin >> c;
    //     if (c == 1) {
    //         int j, x; cin >> j >> x;
    //         --j;
    //         arr[j] = x;
    //         continue;
    //     }

    //     int x; cin >> x;
    //     vi has(4 * n + 1, -1);
    //     int curr = 2 * n;
    //     has[curr] = 0;
    //     bool found = false;
    //     rep(i, 0, n) {
    //         curr += arr[i];
    //         has[curr] = i + 1;

    //         if (curr - x >= 0 && curr - x <= 4 * n && has[curr - x] != -1) {
    //             found = true;
    //             cout << "YES\n";
    //             cout << has[curr - x] + 1 << " " << i + 1 << "\n";
    //             break;
    //         }
    //     }

    //     if (!found) {
    //         cout << "NO\n";
    //     }
    // }
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