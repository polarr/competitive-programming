/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-06-11
 * Contest: Codeforces 1998
 * Problem: C
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
    int n, k; cin >> n >> k;

    vector<pii> a(n);
    rep(i, 0, n){
        cin >> a[i].first;
    }

    int mxi = -1;
    int mx = 0;
    rep(i, 0, n){
        cin >> a[i].second;
        if (a[i].second == 1){
            if (a[i].first > mx){
                mx = a[i].first;
                mxi = i;
            }
        }
    }

    vi b;

    rep(i, 0, n){
        if (i != mxi){
            b.pb(a[i].first);
        }
    }

    sort(all(b));

    ll ans = b[b.size() - 1];

    if (mx != 0){
        ans = a[mxi].first + k;
    } else {
        b.pop_back();
    }

    ans += (ll) b[(b.size() + 1)/2 - 1];

    sort(all(a));
    ll ans2 = a[n - 1].first;
    a.pop_back();
    a.pb({2e9, 0});
    int val = a[n/2 - 1].first;
    int curr = 0;
    rep(i, n/2 - 1, n){
        //cerr << val << endl;
        if (a[i].first == val){
            curr++;
            if (a[i].second == 0){
                break;
            }
        } else {
            int d = a[i].first - val;
            if (k/curr >= d){
                k -= d * curr;
                val += d;
                curr++;
            } else {
                val += k/curr;
                break;
            }

            if (a[i].second == 0){
                break;
            }
        }
    }

    ans2 += val;

    cout << max(ans, ans2) << endl;
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