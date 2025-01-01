/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-05-16
 * Contest: CSES Problemset
 * Problem: 1645. Sorting and Searching - Nearest Smallest Values
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

    vector<int> arr(n);
    vector<pair<int, int>> possible;

    int curr; cin >> curr; arr[0] = curr;
    cout << 0;

    for (int i = 1; i < n; i++){
        int x; cin >> x;
        arr[i] = x;

        if (x > curr){
            cout << " " << i;
            while (possible.size() > 0 && curr <= possible[possible.size() - 1].first){
                possible.pop_back();
            }
            possible.pb(make_pair(curr, i));
            curr = x;
            continue;
        }
        
        curr = x;

        bool found = false;
        for (int j = possible.size() - 1; j >= 0; j--){
            pair <int, int> pot = possible[j];
            if (pot.first < x){
                cout << " " << pot.second;
                found = true;
                break;
            }
        }

        if (!found){
            cout << " " << 0;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}