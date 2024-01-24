/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-01-13
 * Contest: 1920
 * Problem: D
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

map<ull, vector<int>> newVals;
set<ull> repeatI;

int check(ull k){
    ull valNext = *(repeatI.upper_bound(k));
    ull valRange = *(--repeatI.upper_bound(k));
    int s = newVals[valRange].size();
    if (k >= valNext - s){
        return newVals[valRange][s - valNext + k];
    }
    return check(k % valRange);
}

void solve(){
    newVals = {};
    repeatI = {0};
    newVals[0] = {};

    int n, q;
    cin >> n >> q;

    ull valRange = 0;
    ull lastX = 0;
    ull newSize = 0;
    for (int i = 0; i < n; i++){
        int b, x;
        cin >> b >> x;
        if (b == 1){
            newVals[valRange].pb(x);
            newSize++;
            continue;
        }

        ull lastI = *(--repeatI.end());
        ull newI = lastI * (lastX + 1) + newSize;
        lastX = (ull)x;
        newSize = 0;
        repeatI.insert(newI);
        newVals[newI] = {};
        valRange = newI;
    }

    repeatI.insert(*(--repeatI.end()) * (lastX + 1) + newSize);
    
    for (int i = 0; i < q; i++){
        ull k;
        cin >> k;
        k--;
        cout << check(k) << " ";
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