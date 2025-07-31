/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-07-31
 * Contest: 
 * Problem: C3
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

const int SPLITTER = 13;

int query(vi &a){
    string s = "? " + to_string(a.size());
    rep(i, 0, a.size()){
        s += " ";
        s += to_string(a[i]);
    }
    cout << s << endl;
    int x; cin >> x;
    return x;
}

void solve(){
    int n; cin >> n;
    int d = -1;
    int lo = 1, hi = n;
    while (lo < hi){
        int mid = (lo + hi)/2;
        vi a = {};
        rep(i, 1, mid + 1){
            a.pb(i);
        }

        int x = query(a);
        if (x == 0){
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }

    if (lo == n){
        vi a = {};
        rep(i, 1, n + 1){
            a.pb(i);
        }
        int x = query(a);
        if (x == 0){
            d = 1;
        } else {
            d = n;
        }
    } else {
        d = lo;
    }

    int sum = 0;

    vi splits = {};
    int split = 1;
    while (splits.size() < SPLITTER){
        if ((split * (split + 1))/2 > sum){
            splits.pb(split);
            sum += (split * (split + 1))/2;
        }

        split++;
    }

    string ans = "";

    for (int i = 1; i <= n - SPLITTER + 1; i += SPLITTER){
        vi a;
        rep(j, 0, SPLITTER){
            rep(k, 0, splits[j]){
                a.pb(i + j);
                a.pb(d);
            }
            a.pb(d);
        }

        int x = query(a);
        string add = "";
        for (int j = SPLITTER - 1; j >= 0; j--){
            int t = splits[j];
            if (x >= t * (t + 1)/2){
                add += "(";
                x -= t * (t + 1)/2;
            } else {
                add += ")";
            }
        }
        reverse(all(add));
        ans += add;
    }

    if (n % SPLITTER != 0){
        rep(i, SPLITTER * (n/SPLITTER) + 1, n + 1){
            vi a = {i, d};
            int x = query(a);
            if (x == 0){
                ans += ")";
            } else {
                ans += "(";
            }
        }
    }

    cout << "! " << ans << endl;
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