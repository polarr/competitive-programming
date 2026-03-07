/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2026-03-06
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

void solve(){
    int n, q; cin >> n >> q;

    int N = 1 << n;

    vi skill(N);
    rep(i, 0, N) cin >> skill[i];

    vi xsum(2 * N);

    function<void(int)> dfs;
    dfs = [&](int node) {
        if (node >= N) {
            xsum[node] = skill[node - N];
            return;
        }

        int a = node * 2, b = node * 2 + 1;
        dfs(a);
        dfs(b);
        
        xsum[node] = xsum[a] ^ xsum[b];
    };

    dfs(1);

    rep(qq, 0, q) {
        int b, c; cin >> b >> c;
        --b;

        int above = 0;
        int at = b + N;
        int curr = c;
        int num = 1;

        while (at != 1) {
            int nx = at/2;
            int other = at ^ 1;

            if (curr > xsum[other] || (curr == xsum[other] && at % 2 == 0)) {
                curr ^= xsum[other];
            } else {
                above += num;
                curr ^= xsum[other];
            }

            at = nx;

            num *= 2;
        }

        cout << above << endl;
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