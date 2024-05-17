/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-05-16
 * Contest: CSES Problemset - Sorting and Searching
 * Problem: 1077 - Sliding Window Cost
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

double encode(ll x, int i){
    return 1.0 * x + 1.0/(i + 2);
}

void solve(){
    int n, k; cin >> n >> k;

    Tree<double> curr;
    vector<ll> arr;

    ll sum = 0;
    for (int i = 0; i < n; i++){
        ll x; cin >> x;
        arr.pb(x);
    }

    for (int i = 0; i < k; i++){
        curr.insert(encode(arr[i], i));
    }

    ll median = static_cast<ll>(*curr.find_by_order((k + 1)/2 - 1));

    ll cost = 0;
    for (int i = 0; i < k; i++){
        cost += abs(arr[i] - median);
    }

    cout << cost;

    for (int i = k; i < n; i++){
        curr.erase(encode(arr[i - k], i - k));
        curr.insert(encode(arr[i], i));

        cost -= abs(median - arr[i - k]);

        ll temp = median;

        median = static_cast<ll>(*curr.find_by_order((k + 1)/2 - 1));

        if (k % 2 == 0){
            cost += temp - median;
        }

        cost += abs(median - arr[i]);

        cout << " " << cost;
    }

    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}