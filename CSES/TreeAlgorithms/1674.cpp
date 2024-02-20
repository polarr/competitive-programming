/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-02-20
 * Contest: CSES Problemset - Tree Algorithms
 * Problem: 1674 - Subordinates
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

vector<vector<int>> children;
vector<int> subordinates;


int dfs(int x){
    if (subordinates[x] > 0){
        return subordinates[x];
    }

    int subs = 1;
    for (int y : children[x]){
        subs += dfs(y);
    }
    
    subordinates[x] = subs;
    return subs;
}

void solve(){
    int n;
    cin >> n;

    children = vector<vector<int>>(n + 1);
    subordinates = vector<int>(n + 1, 0);

    for (int i = 1; i < n; i++){
        int boss;
        cin >> boss;
        children[boss].pb(i + 1);
    }

    dfs(1);

    for (int i = 1; i < n; i++){
        cout << subordinates[i] - 1 << " ";
    }

    cout << subordinates[n] - 1 << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}	