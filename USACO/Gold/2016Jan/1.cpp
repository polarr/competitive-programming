/**
 * Solution by 1egend
 * Date: 2024-02-13
 * Contest: USACO 2016 January
 * Problem: Gold P1. Angry Cows
**/

#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;

const string iofilename = "angry";
ifstream fin(iofilename + ".in");
ofstream fout(iofilename + ".out");

vector<false> visited;
vector<vector<pair<int, int>>> adj;

int count = 0;
void dfs(int x, int r){
    if (visited[x]){
        return;
    }

    visited[x] = true;
    count++;

    for (pair<int, int> n : adj[x]){
        if (n.second <= r){
            dfs(n.first, r);
        }
    }
}

// Use fstream (fin, fout) instead of iostream!
void solve(){
    int n;
    cin >> n;

    visited = vector<int>(n, false);
    adj = vector<vector<pair<int, int>>>(n, vector<pair<int, int>>(n));
    vector<int> pos(n, 0);
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        pos[i] = x;
    }

    for (int i = 0; i < n - 1; i++){
        for (int j = i + 1; j < n; j++){
            int d = abs(pos[i] - pos[j]);
            adj[i].push(make_pair(j, d));
            adj[j].push(make_pair(i, d));
        }
    }

    ll left = 0;
    ll right = 1e9;
    while(left < right){
        ll mid =  (left + right)/2;
        if (){

        }
    }

    cout << left << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    fin.tie(0); cout.tie(0);
    
    solve();
    return 0;
}