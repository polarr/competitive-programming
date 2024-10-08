/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-10-07
 * Contest: CSES Problemset - Sorting and Searching
 * Problem: 2169
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
    int n; cin >> n;

    vector<tuple<int, int, int>> ranges(n);
    Tree<pair<int, int>> starts;
    Tree<pair<int, int>> ends;
    
    for (int i = 0; i < n; i++){
        int x, y; cin >> x >> y;
        ranges[i] = {x, -y, i};

        ends.insert({y, -x});
    }

    sort(ranges.begin(), ranges.end());

    vector<pair<int, int>> ans(n);

    for (int i = 0; i < n; i++){
        tuple<int, int, int> r = ranges[i];
        int x = get<0>(r), y = -get<1>(r), j = get<2>(r);
        starts.insert({y, -x});

        int hasother = ends.order_of_key({y, -x});
        ends.erase({y, -x});

        int otherhas = starts.size() - starts.order_of_key({y, -x}) - 1;
        ans[j] = {hasother, otherhas};
    }

    for (int i = 0; i < n; i++){
        cout << ans[i].first << " ";
    }

    cout << endl;

    for (int i = 0; i < n; i++){
        cout << ans[i].second << " ";
    }

    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}