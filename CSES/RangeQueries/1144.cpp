/**
 * Solution by 1egend (polarity.sh)
 * Date: 2025-01-30
 * Contest: CSES Problemset
 * Problem: 1144
**/

#include <bits/stdc++.h>
using namespace std;

// Order statistic tree
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

template<class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag,
    tree_order_statistics_node_update>;

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
    vi salaries(n);
    Tree<pii> ost;
    rep(i, 0, n){
        cin >> salaries[i];
        ost.insert({salaries[i], i});
    }

    rep(i, 0, q){
        char c; cin >> c;
        if (c == '!'){
            int k, x; cin >> k >> x;
            --k;
            ost.erase({salaries[k], k});
            salaries[k] = x;
            ost.insert({x, k});
            continue;
        }

        int a, b; cin >> a >> b;

        cout << (ost.order_of_key({b, n}) - ost.order_of_key({a, -1})) << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}