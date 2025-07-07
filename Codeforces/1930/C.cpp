/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-07-05
 * Contest: Codeforces 1930
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
    int n; cin >> n;
    vi arr(n);
    rep(i, 0, n) cin >> arr[i];

    set<pii> curr;

    auto add = [&](int x){
        auto j = curr.lower_bound({x + 1, 0});
        int lo = x, hi = x;
        if (j != curr.begin()){
            auto k = prev(j);
            pii range = *k;
            if (range.second == x - 1){
                lo = range.first;
                curr.erase(k);
            }
        }
        if (j != curr.end()){
            pii range = *j;
            if (range.first == x + 1){
                hi = range.second;
                curr.erase(j);
            }
        }
        curr.insert({lo, hi});
    };

    rep(i, 0, n){
        int x = arr[i] + i + 1;
        if (curr.size() == 0){
            add(x);
            continue;
        }

        auto j = curr.lower_bound({x + 1, 0});
        if (j == curr.begin()){
            add(x);
            continue;
        }

        pii range = *prev(j);
        if (range.second < x){
            add(x);
        } else {
            int can = range.first - 1;
            if (x - can <= i){
                add(can);
            }
        }

        // for (pii range : curr){
        //     cerr << range.first << " " << range.second << endl;
        // }

        // cerr << endl;
    }

    vi ans;
    for (pii range : curr){
        rep(i, range.first, range.second + 1){
            ans.pb(i);
        }
    }

    reverse(all(ans));
    for (int a : ans){
        cout << a << " ";
    }

    cout << endl;
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