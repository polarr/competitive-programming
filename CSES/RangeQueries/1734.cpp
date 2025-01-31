/**
 * Solution by 1egend (polarity.sh)
 * Date: 2025-01-30
 * Contest: CSES Problemset
 * Problem: 1749
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

    vi arr(n);
    rep(i, 0, n){
        cin >> arr[i];
    }

    vector<array<int, 3>> queries(q);
    rep(i, 0, q){
        int a, b; cin >> a >> b;
        --a; --b;
        queries[i] = {b, a, i};
    }

    vi ans(q);

    sort(all(queries));

    map<int, bool> found;
    map<int, int> lastIndex;
    Tree<pii> last;

    int j = 0;
    int curr = 0;
    rep(i, 0, n){
        if (!found[arr[i]]){
            found[arr[i]] = true;
            curr++;
        }

        last.erase({lastIndex[arr[i]], arr[i]});
        lastIndex[arr[i]] = i;
        last.insert({i, arr[i]});

        while (j < q && i == queries[j][0]){
            int a = queries[j][1];
            ans[queries[j][2]] = curr - last.order_of_key({a, -1});
            j++;
        }
    }

    rep(i, 0, q){
        cout << ans[i] << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}