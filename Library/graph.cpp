/**
 * Template by 1egend (polarity.sh)
 * Template: graph
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = LLONG_MAX;

/** ALGORITHM: 0/1 BFS 
 *  PURPOSE: Finds shortest path in 0/1 weighted simple graph front node 0 to all nodes
 *  TIME: O(V + E)
*/
void zero_one_bfs(){
    int n; vector<vector<pair<int, int>>> adj;

    vector<int> d(n, INF);
    d[0] = 0;
    deque<int> q;
    q.push_front(0);
    while (!q.empty()) {
        int v = q.front();
        q.pop_front();
        for (auto edge : adj[v]) {
            int u = edge.first;
            int w = edge.second;
            if (d[v] + w < d[u]) {
                d[u] = d[v] + w;
                if (w == 1)
                    q.push_back(u);
                else
                    q.push_front(u);
            }
        }
    }
}



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    return 0;
}