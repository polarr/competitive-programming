/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-11-12
 * Contest: AtCoder arc084
 * Problem: D
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

void solve(){
    int k; cin >> k;

    vector<int> dist(k, INT_MAX);
    deque<int> q;
    q.push_front(1);
    dist[1] = 0;

    while(!q.empty()){
        int n = q.front();
        q.pop_front();

        vector<pair<int, int>> adj = {{(n + 1) % k, 1}, {n * 10 % k, 0}};

        for (pair<int, int> e : adj){
            if (dist[n] + e.second < dist[e.first]){
                dist[e.first] = dist[n] + e.second;
                if (e.second == 0){
                    q.push_front(e.first);
                } else {
                    q.push_back(e.first);
                }
            }
        }
    }

    cout << dist[0] + 1 << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}