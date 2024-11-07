/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-11-04
 * Contest: USACO 2016 Dec Gold
 * Problem: 3
**/

#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const int INF = 1e9;

const string iofilename = "lasers";
ifstream fin(iofilename + ".in");
ofstream fout(iofilename + ".out");

vector<pair<int, int>> cardinal = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

// Use fstream (fin, fout) instead of iostream!
void solve(){
    /** NOTE: I overcomplicated this with dijkstra but it passes, you can simply pure bfs and just subtract 1 from the first direction being free */
    int n, sh, sw, eh, ew; fin >> n >> sh >> sw >> eh >> ew;
    pair<int, int> s = {sh, sw}, e = {eh, ew};

    map<pair<int, int>, int> dist;
    map<pair<int, int>, bitset<4>> dir;
    map<int, set<int>> fenceh;
    map<int, set<int>> fencew;
    for (int i = 0; i < n; i++){
        int fh, fw; fin >> fh >> fw;
        dist[{fh, fw}] = INF;
        dir[{fh, fw}] = bitset<4>{"0000"};
        fenceh[fh].insert(fw);
        fencew[fw].insert(fh);
    }

    fenceh[sh].insert(sw);
    fencew[sw].insert(sh);

    fenceh[eh].insert(ew);
    fencew[ew].insert(eh);
    dist[e] = INF;
    dir[e] = bitset<4>{"0000"};

    deque<pair<int, int>> q;
    q.push_front(s);
    dist[s] = 0;
    dir[s] = bitset<4>{"1111"};

    auto update = [&](pair<int, int>& curr, pair<int, int> node, int d){
        int w = 1;

        if (dir[curr][d]){
            w = 0;
        }

        if (dist[curr] + w < dist[node] || (dist[curr] + w == dist[node] && !dir[node][d])){
            if (dist[curr] + w < dist[node]){
                dir[node].reset();
            }
            dist[node] = dist[curr] + w;
            dir[node].set(d, true);
            if (w == 0){
                q.push_front(node);
            } else {
                q.push_back(node);
            }

            // fout << curr.first << " " << curr.second << " hit " << node.first << " " << node.second << " " << d << endl;
        }
    };

    while (!q.empty()) {
        pair<int, int> v = q.front();
        q.pop_front();

        auto d = fencew[v.second].upper_bound(v.first);
        auto u = prev(prev(d));
        auto r = fenceh[v.first].upper_bound(v.second);
        auto l = prev(prev(r));

        if (d != fencew[v.second].end()){
            update(v, {*d, v.second}, 0);
        }

        if (u != prev(fencew[v.second].begin())){
            update(v, {*u, v.second}, 1);
        }

        if (r != fenceh[v.first].end()){
            update(v, {v.first, *r}, 2);
        }

        if (l != prev(fenceh[v.first].begin())){
            update(v, {v.first, *l}, 3);
        }

        // for (auto edge : adj[v]) {
        //     int u = edge.first;
        //     int w = edge.second;
        //     if (d[v] + w < d[u]) {
        //         d[u] = d[v] + w;
        //         if (w == 1)
        //             q.push_back(u);
        //         else
        //             q.push_front(u);
        //     }
        // }
    }

    if (dist[e] == INF){
        fout << -1 << endl;
        return;
    }

    fout << dist[e] << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    solve();
    return 0;
}