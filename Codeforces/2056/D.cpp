/**
 * Solution by 1egend (polarity.sh)
 * Date: 2025-02-01
 * Contest: Codeforces 2056
 * Problem: D
**/

#include <bits/stdc++.h>
using namespace std;

// Order statistic tree
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class T>
using Tree =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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
    rep(i, 0, n){
        cin >> arr[i];
    }

    ll ans = 0;

    rep(k, 1, 11){
        vi smaller(n, 0);
        vi larger(n, 0);
        vi eq(n, 0);
        Tree<pii> cnt1, cnt2;
        int j = 0;
        rep(i, 0, n){
            if (arr[i] < k){
                smaller[i] = (i == 0 ? 0: smaller[i - 1]) + 1;
            }
            if (arr[i] > k){
                larger[i] = (i == 0 ? 0: larger[i - 1]) + 1;
            }
            if (arr[i] == k){
                eq[i] = (i == 0 ? 0: eq[i - 1]) + 1;
            }

            if (arr[i] == k){
                while (j < i){
                    cnt1.insert({2 * smaller[j] - j, j});
                    cnt2.insert({2 * larger[j] - j, j});
                    j++;
                }
            }

            ans += cnt1.size() - cnt1.order_of_key({2 * eq[i] + 2 * larger[i] - 2 * eq[i] - i, -1});
            ans += cnt2.size() - cnt2.order_of_key({2 * larger[i] - i, n});
        }
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