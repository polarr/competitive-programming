/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-12-31
 * Contest: CSES Problemset - Sorting and Searching
 * Problem: 1645
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
    stack<pair<int, int>> s;
    for (int i = 0; i < n; i++){
        int a; cin >> a;

        int ans = 0;

        while(!s.empty()){
            pair<int, int> t = s.top();

            if (t.first < a){
                ans = t.second + 1;
                break;
            }

            s.pop();
        }

        s.push({a, i});

        cout << ans << " ";
    }

    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}