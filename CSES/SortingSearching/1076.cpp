/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-05-10
 * Contest: CSES Problemset - Sorting and Searching
 * Problem: 1076 - Slidng Window Median
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

    Tree<double> curr;
    vector<double> arr;
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        arr.pb(1.0 * x + 1.0/(i + 2));
    }

    for (int i = 0; i < k; i++){
        curr.insert(arr[i]);
    }

    cout <<  static_cast<int>(*curr.find_by_order((k + 1)/2 - 1));

    for (int i = k; i < n; i++){
        curr.erase(arr[i - k]);
        curr.insert(arr[i]);

        cout << " " << static_cast<int>(*curr.find_by_order((k + 1)/2 - 1));
    }

    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}