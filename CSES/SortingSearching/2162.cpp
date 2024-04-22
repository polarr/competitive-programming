/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-04-17
 * Contest: CSES Problemset
 * Problem: 2162. Sorting and Searching - Josephus Problem
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

void solve(){
    int n; cin >> n;

    vector<int> children;
    for (int i = 0; i < n; i++){
        if (i % 2 == 1){
            cout << i + 1 << " "; // massive n prune, so O(n^2) passes
            continue;
        }
        children.pb(i + 1);
    }

    int curr = (n % 2 == 0 ? 0:-1);
    while(children.size() > 0){
        curr++;
        curr %= children.size();
        cout << children[curr] << " ";
        children.erase(children.begin() + curr);
    }

    /**
    int children = n;
    int r = 0;
    int m = 2;
    int child = 0;
    while(children > 0){
        child += m;

        if (child <= n){
            m *= 2;
            r = (child + 1) % m;
        }
        cout << child << " ";
        children--;
    }
    **/
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}