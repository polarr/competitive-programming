/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-02-11
 * Contest: CSES Problemset - Sorting and Searching
 * Problem: 1073 - Towers
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

void solve(){
    int n;
    cin >> n;
    multiset<int> towers;
    for (int i = 0; i < n; i++){
        int k;
        cin >> k;
        if (towers.upper_bound(k) != towers.end()){
            towers.erase(towers.upper_bound(k));
        }

        towers.insert(k);
    }

    cout << towers.size() << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}