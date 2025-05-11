/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-05-11
 * Contest: Codeforces 2102
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

// debugged and passed this 1 minute post-contest... rip CM

void solve(){
    int n; cin >> n;
    vi a(n);
    rep(i, 0, n){
        cin >> a[i];
    }

    vi b = a;
    sort(all(b));

    int cnt = 1;
    int i = 0;
    while (i < n){
        if (b[i] < cnt){
            i++;
            continue;
        }

        if (n - i >= 2){
            i += 2;
            cnt++;
            continue;
        }

        break;
    }

    --cnt; // can place 1 ... cnt

    // cout << cnt << endl;

    set<int> x, y;
    rep(i, 1, cnt + 1){
        x.insert(i);
        y.insert(i);
    }

    vl add, sub;
    vector<bool> taken(n, false);

    // rep(i, 0, n){
    //     auto j = x.upper_bound(a[i]);
    //     if (j == x.begin()){
    //         continue;
    //     }

    //     j = prev(j);
    //     x.erase(j);
    //     taken[i] = true;
    //     sub.pb(i);

    //     if (x.empty()) break;
    // }

    // for (int i = n - 1; i >= 0; i--){
    //     if (taken[i]) continue;
    //     auto j = y.upper_bound(a[i]);
    //     if (j == y.begin()){
    //         continue;
    //     }

    //     j = prev(j);
    //     y.erase(j);
    //     add.pb(i);

    //     if (y.empty()) break;
    // }

    i = 0; int j = n - 1;
    bool turn = false;
    while (i <= j){
        if (!turn){
            auto k = x.upper_bound(a[i]);
            if (k == x.begin()){
                i++;
                continue;
            }

            k = prev(k);
            x.erase(k);
            taken[i] = true;

            sub.pb(i);
            i++;

            turn = !turn;
        } else {
            auto k = y.upper_bound(a[j]);
            if (k == y.begin()){
                j--;
                continue;
            }

            k = prev(k);
            y.erase(k);
            taken[j] = true;

            add.pb(j);
            j--;

            turn = !turn;

            if (y.empty()) break;
        }
    }

    // debug_out(add);

    // sort(all(add));
    // sort(all(sub));
    // reverse(all(sub));

    ll ans = 0;

    rep(ii, 0, min(add.size(), sub.size())){
        // if (add[i] - sub[i] > 0){
        //     ans += add[i] - sub[i];
        // }
        ans += (ll)(add[ii] - sub[ii]);
    }

    cout << ans << endl;
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