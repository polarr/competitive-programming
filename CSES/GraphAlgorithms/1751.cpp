/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-02-20
 * Contest: CSES Problemset - Graph Algorithms
 * Problem: 1751 - Planets Cycles
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

vector<int> succ;
vector<int> ans;
vector<int> visited;

int in_cycle = -1;

void dfs(int x, int count){
    if (ans[x] > -1){
        return;
    }

    if (visited[x] > -1){
        ans[x] = count - visited[x];
        in_cycle = count - visited[x];
        in_cycle--;
        return;
    }

    visited[x] = count;
    dfs(succ[x], count + 1);

    if (in_cycle > 0){
        ans[x] = ans[succ[x]];
        in_cycle--;
    } else if (in_cycle == 0){
        in_cycle--;
        return;
    } else {
        ans[x] = 1 + ans[succ[x]];
    }
}

void solve(){
    int n;
    cin >> n;
    
    succ = vector<int>(n + 1);
    ans = vector<int>(n + 1, -1);
    visited = vector<int>(n + 1, -1);

    for (int i = 0; i < n; i++){
        int t;
        cin >> t;
        succ[i + 1] = t;
    }

    for (int i = 1; i < n + 1; i++){
        dfs(i, 0);
    }

    for (int i = 1; i < n; i++){
        cout << ans[i] << " ";
    }

    cout << ans[n] << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}