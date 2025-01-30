/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-12-27
 * Contest: CSES Problemset
 * Problem: 1757
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

// vector<bool> ccvisited;
// vector<vector<int>> components;

// void floodfill(vector<vector<int>> &adj, int node, int comp){
//     if (ccvisited[node]){
//         return;
//     }

//     ccvisited[node] = true;
//     components[comp].pb(node);

//     for (int i : adj[node]){
//         floodfill(adj, i, comp);
//     }
// }

// void solve(){
//     int n, m; cin >> n >> m;
    
//     vector<vector<int>> adj(n);
    
//     vector<bool> visited(n, false);
//     vector<int> degree(n, 0);
//     for (int i = 0; i < m; i++){
//         int a, b; cin >> a >> b;
//         --a; --b;

//         adj[a].pb(b);
//         degree[b]++;
//     }


//     ccvisited = vector<bool>(n, false);
//     components = vector<vector<int>>(n);

//     int c = 0;

//     for (int i = 0; i < n; i++){
//         if (!ccvisited[i]){
//             floodfill(adj, i, c);
//             c++;
//         }
//     }

//     vector<vector<int>> ans;
//     vector<int> whichcc(n);

//     for (int cc = 0; cc < n; cc++){
//         vector<int> nodes = components[cc];

//         if (nodes.size() == 0){
//             break;
//         }

//         using T = int;
//         priority_queue<T, vector<T>, greater<T>> pq;

//         for (int i = 0; i < nodes.size(); i++){
//             if (degree[nodes[i]] == 0){
//                 pq.push(nodes[i]);
//             }
//         }

//         ans.pb({});

//         while (!pq.empty()){
//             int node = pq.top();
//             pq.pop();

//             if (visited[node]){
//                 continue;
//             }

//             visited[node] = true;
//             whichcc[node] = cc;
//             ans[cc].pb(node);

//             for (int i : adj[node]){
//                 degree[i]--;
//                 if (degree[i] == 0){
//                     pq.push(i);
//                 }
//             }
//         }
//     }

//     vector<bool> targeted(n, false);
//     vector<int> currAt(n, 0);
//     vector<int> a;

//     for (int target = 0; target < n; target++){
//         if (targeted[target]){
//             continue;
//         }

//         int cc = whichcc[target];
//         int i = currAt[cc];
//         while (true){
//             int node = ans[cc][i];

//             targeted[node] = true;
//             a.pb(node);

//             if (node == target){
//                 currAt[cc] = i + 1;
//                 break;
//             }
//             i++;
//         }
//     }

//     for (int i = 0; i < a.size(); i++){
//         cout << a[i] + 1 << " ";
//     }

//     cout << endl;
// }

/** 
 * ALGORITHM: Topological Sort
 * PURPOSE: Sorts a DAG IN-PLACE such that each directed edge points forward
 * CONSTRAINT: Graph must be a DAG
 * TIME: O(V)
*/
vector<int> toposort(int n, vector<vector<int>> &adj){
    vector<int> degree(n, 0);
    priority_queue<int> q; // use pq for lexicographical sorting
    for (int i = 0; i < n; i++){
        for (int j : adj[i]){
            degree[j]++;
        }
    }

    for (int i = 0; i < n; i++){
        if (degree[i] == 0){
            q.push(i);
        }
    }

    vector<int> ans;

    while(!q.empty()){
        int i = q.top();
        ans.pb(i);
        q.pop();

        for (int j : adj[i]){
            if (degree[j] == 0){
                continue;
            }

            degree[j]--;
            if (degree[j] == 0){
                q.push(j);
            }
        }
    }

    return ans;
}

void solve(){
    int n, m; cin >> n >> m;

    vector<vector<int>> adj = vector<vector<int>>(n);

    for (int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        --a; --b;

        adj[b].pb(a);
    }

    vector<int> ans = toposort(n, adj);

    reverse(ans.begin(), ans.end());
    
    for (int i = 0; i < n; i++){
        cout << ans[i] + 1 << " ";
    }

    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}