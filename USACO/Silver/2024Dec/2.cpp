/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-12-13
 * Contest: USACO 2024 December Silver
 * Problem: 2
**/

#include <bits/stdc++.h>
using namespace std;

// Order statistic tree
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class T>
using Tree =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

void solve(){
    int n, k; cin >> n >> k;

    vector<array<int, 4>> events;
    Tree<pair<int, int>> trees;
    for (int i = 0; i < n; i++){
        int t; cin >> t;
        events.pb({t, 1, -1, -1});
        trees.insert({t, i});
    }

    vector<int> res(k);
    for (int i = 0; i < k; i++){
        int l, r, t; cin >> l >> r >> t;

        int lenience = (trees.order_of_key({r, n}) - trees.order_of_key({l, -1})) - t;

        events.pb({l, 0, lenience, i});
        events.pb({r, 2, lenience, i});
    }

    sort(events.begin(), events.end());

    int tt = 0;

    multiset<int> leniences;

    for (int i = 0; i < events.size(); i++){
        array<int, 4> event = events[i];
        if (event[1] == 0){
            int adj = event[2] + tt;
            leniences.insert(adj);
            res[event[3]] = adj;
        } else if (event[1] == 2){
            leniences.erase(leniences.find(res[event[3]]));
        } else {
            if (leniences.empty() || *(leniences.begin()) - tt > 0){
                tt++;
            }
        }
    }

    cout << tt << endl;

    /**
    for (int i = 0; i < k - 1; i++){
        // prune useless intervals
        if (res[i + 1][2] >= res[i][2] && res[i + 1][1] <= res[i][1]){
            continue;
        }

        temp.insert(res[i]);
    }
    */
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