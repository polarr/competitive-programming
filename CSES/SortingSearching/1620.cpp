/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-05-10
 * Contest: CSES Problemset - Sorting and Searching
 * Problem: 1620 - Factory Machines
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

void solve(){
    int n; ull t; cin >> n >> t;

    vector<ull> machines;
    for (int i = 0; i < n; i++){
        ull k; cin >> k;
        machines.pb(k);
    }

    ull left = 0;
    ull right = LLONG_MAX;

    while (left < right){
        ull mid = (left + right)/2;
        ull products = 0;
        for (int i = 0; i < machines.size(); i++){
            products += mid/machines[i];
        }

        if (products >= t){
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    assert(left == right);

    cout << left << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}