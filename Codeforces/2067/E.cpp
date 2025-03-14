/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-03-13
 * Contest: Codeforces 2067
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

    vi a(n);

    int cnt = 0;
    int fz = -1;
    rep(i, 0, n){
        cin >> a[i];
        if (a[i] != 0){
            cnt++;
        } else if (fz == -1){
            fz = i;
        }
    }

    if (fz == -1){
        cout << cnt << endl;
        return;
    }

    bool good = true;
    map<int, bool> has;
    vi pre(n + 1, -1);
    for (int i = n - 1; i >= 0; i--){
        int x = a[i];
        if (i != fz && x == 0){
            continue;
        }
        if (pre[i + 1] >= x){
            good = false;
            break;
        }

        has[x] = true;
        pre[i] = pre[i + 1];
        while (has[pre[i] + 1]){
            pre[i]++;
        }
    }

    if (good){
        cnt++;
    }

    cout << cnt << endl;
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