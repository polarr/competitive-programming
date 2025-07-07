/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-07-06
 * Contest: 
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
    
    ll sum = 0;
    ll mx = 0;
    vl arr(n);
    vl pre(n + 1, 0);
    rep(i, 0, n) {
        cin >> arr[i];
        sum += arr[i];
        mx = max(mx, arr[i]);
        pre[i + 1] = sum;
    }

    if (sum % 2 == 1 || 2 * mx > sum){
        cout << -1 << endl;
        return;
    }

    int lo = 0, hi = n - 1;
    while (lo < hi){
        int mid = (lo + hi)/2;

        if (2 * pre[mid + 1] > sum){
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }

    int j = lo;
    ll has = pre[j + 1] - sum/2;
    ll diff = arr[j] - has;

    vector<array<ll, 3>> matches;

    rep(i, 0, lo + 1){
        ll curr = arr[i];
        if (i == lo){
            curr = diff;
        }
        while (curr > 0){
            // cerr << i << " " << j << endl;
            ll sub = min(curr, has);
            matches.pb({j, i, sub});
            curr -= sub;
            has -= sub;

            if (has == 0){
                j++;
                if (j != n) has = arr[j];
            }
        }
    }

    // cerr << endl;

    sort(all(matches));

    vector<vl> op;

    vl currOp(n, 0);

    mx = -1;
    int ans = 0;
    for (array<ll, 3> &match : matches){
        if (match[1] <= mx) {
            currOp[match[0]]+= match[2];
            currOp[match[1]]+= match[2];
            continue;
        }

        if (ans != 0) op.pb(currOp);

        ans++;
        mx = match[0] - 1;

        currOp = vl(n, 0);
        currOp[match[0]]+= match[2];
        currOp[match[1]]+= match[2];
    }

    op.pb(currOp);

    cout << ans << endl;

    rep(i, 0, op.size()){
        rep(j, 0, n){
            cout << op[i][j] << " ";
        }

        cout << endl;
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