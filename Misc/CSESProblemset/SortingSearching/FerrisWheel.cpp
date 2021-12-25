/**
 * Solution by 1egend
 * Date:
 * Contest: Codeforces Round 
 * Problem: 
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

void solve(){
    int n, x;
    cin >> n >> x;
    multiset<int> c;
    for (int i = 0; i < n; ++i){
        static int t;
        cin >> t;
        c.insert(t);
    }

    int ans = 0;
    while(c.size() != 0){
        ++ans;
        if (c.size() > 1 && *(--c.end()) + *c.begin() <= x){
            c.erase(--c.end());
            c.erase(c.begin());
            continue;
        }

        c.erase(--c.end());
    }
    cout << ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}