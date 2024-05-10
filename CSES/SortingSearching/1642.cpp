/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-05-10
 * Contest: CSES Problemset - Sorting and Searching
 * Problem: 1642 - Sum of Four Values
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

void solve(){
        ll n, x;
    cin >> n >> x;
    vector<pair<int, int>> arr;
    for (int i = 0; i < n; i++){
        int a;
        cin >> a;
        arr.pb(make_pair(a, i + 1));
    }
    sort(arr.begin(), arr.end());
 
    for (ll start = 0; start < n - 3; start++){
        for (ll second = start + 1; second < n - 2; second++){
            int left = second + 1;
            int right = n - 1;
            while (left < right){
                ll sum = arr[start].first + arr[second].first + arr[left].first + arr[right].first;
                if (sum == x){
                    cout << arr[left].second << " " << arr[second].second << " " << arr[right].second << " " << arr[start].second << endl;
                    return;
                }
    
                if (sum < x){
                    ++left;
                } else {
                    --right;
                }
            }
        }
    }
 
    cout << "IMPOSSIBLE" << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}