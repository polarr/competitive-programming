/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-03-30
 * Contest: Codeforces Round 1942
 * Problem: B. Bessie and MEX
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

    set<int> remain;
    for (int i = 0; i < n; i++){
        remain.insert(i);
    }

    int mex = 0;
    vector<int> p;
    for (int i = 0; i < n; i++){
        int a;
        cin >> a;
        if (a > 0){
            p.pb(mex);
            remain.erase(mex);
            mex = *remain.begin();
            continue;
        }

        p.pb(mex - a);
        remain.erase(mex - a);
    }

    cout << p[0];

    for (int i = 1; i < n; i++){
        cout << " " << p[i];
    }

    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for (int t = 1; t <= tc; ++t){
        // cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}