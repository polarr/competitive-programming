/**
 * Template by 1egend (polarity.sh)
 * Template: graph
**/

#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using pii = pair<int, int>;
#define pb push_back
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = LLONG_MAX;

/** 
 * ALGORITHM: 0/1 BFS 
 * PURPOSE: Finds shortest path in 0/1 weighted simple graph front node x to all nodes
 * CONSTRAINT: x < n
 * TIME: O(V + E)
*/
vector<int> deque_bfs(int n, vector<vector<pair<int, int>>> &adj, int x){
    vector<int> d(n, INF);
    d[x] = 0;
    deque<int> q;
    q.push_front(x);
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

    return d;
}

/** 
 * ALGORITHM: Dijkstra's Algorithm
 * PURPOSE: Finds shortest path in nonnegative weighted simple graph from node x to all nodes
 * TIME: O(V + E)
*/
vector<ll> dijkstra(int n, vector<vector<pair<int, ll>>> &adj, int x){
    vector<ll> d(n, INF);
    d[x] = 0;

    using T = pair<ll, int>;
    priority_queue<T, vector<T>, greater<T>> pq;

    pq.push({0, x});

    // U dijkstra
    while(!pq.empty()){
        auto [dist, k] = pq.top();
        pq.pop();

        if (dist != d[k]) { continue; }

        for (pair<int, ll> &node: adj[k]){
            if (dist + node.second < d[node.first]){
                d[node.first] = dist + node.second;
                pq.push({d[node.first], node.first});
            }
        }
    }

    return d;
}

/** 
 * DS: Disjoint Set Union 
 * PURPOSE: Dynamically updates connectedness of graph by adding edges
 * TIME: amortized O(a(N)) to query
*/
class DSU {
    private: 
        vector<int> parents;
        vector<int> sizes;
    
    public:
        DSU(int size) : parents(size), sizes(size, 1){
            for (int i = 0; i < size; i++){
                parents[i] = i;
            }
        }

        int find(int x){
            return (parents[x] == x ? x : (parents[x] = find(parents[x])));
        }

        bool unite(int a, int b){
            int parentA = find(a);
            int parentB = find(b);
            if (parentA == parentB){
                return false;
            }

            if (sizes[parentA] > sizes[parentB]){
                swap(parentA, parentB);
            }

            sizes[parentB] += sizes[parentA];
            parents[parentA] = parentB;
            return true;
        }

        bool connected(int a, int b){
            return find(a) == find(b);
        }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    return 0;
}