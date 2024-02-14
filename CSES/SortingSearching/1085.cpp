/**
 * Solution by 1egend
 * Date: 2024-2-12
 * Contest: CSES Problemset - Sorting and Searching
 * Problem: 1085 - Array Division
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

vector<int> arr;

bool possible(ll mx, int k){
    int divs = 0;
    ll sum = 0;
    for (int i = 0; i < arr.size(); i++){
        if (arr[i] > mx){
            return false;
        }

        if (sum + arr[i] > mx){
            divs++;
            sum = 0;
        }

        sum += arr[i];

        if (divs + 1 > k){
            return false;
        }
    }

    return true;
}

void solve(){
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        arr.pb(x);
    }

    ll l = 1;
    ll r = 2e5 * 1e9;
    while (l < r){
        ll mid = (l + r)/2;
        if (possible(mid, k)){
            r = mid;
        } else {
            l = mid + 1;
        }
    }

    cout << l << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}	