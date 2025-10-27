/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-10-24
 * Contest: Codeforces 2150
 * Problem: A
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
    int n, m; cin >> n >> m;
    string s; cin >> s;
    vi a(n);
    rep(i, 0, n){
        a[i] = s[i] - 'A';
    }

    Tree<int> cells;
    rep(i, 0, m){
        int x; cin >> x;
        cells.insert(x);
    }

    int curr = 1;
    int prev = 1;

    auto step = [&](int i){
        if (a[i] == 0){
            curr++;
        } else {
            if (cells.find(curr + 1) == cells.end()){
                curr++;
                return;
            }

            int l = cells.order_of_key(curr + 1);
            int lo = curr + 1;
            int hi = 1e9;
            while (lo < hi){
                int mid = (lo + hi)/2;
                if (cells.find(mid) == cells.end()){
                    hi = mid;
                    continue;
                }

                int r = cells.order_of_key(mid);
                if (r - l == mid - curr - 1){
                    lo = mid + 1;
                } else {
                    hi = mid;
                }
            }

            curr = lo;
        }
    };

    step(0);

    cells.insert(curr);

    rep(i, 1, n){
        curr = prev;
        step(i - 1);
        prev = curr;
        step(i);

        cells.insert(curr);
    }

    cout << sz(cells) << endl;
    for (int x : cells){
        cout << x << " ";
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