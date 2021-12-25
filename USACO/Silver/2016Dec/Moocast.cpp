/**
 * Solution by 1egend
 * Date: 2021-12-13
 * Contest: USACO 2016 Dec
 * Problem: Silver P3. Moocast
**/

#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;

const string iofilename = "moocast";
ifstream fin(iofilename + ".in");
ofstream fout(iofilename + ".out");

struct Cow {
    int x, y, w;
    Cow(int a, int b, int p):
    x(a), y(b), w(p)
    {}
};

int n;
vector <int> adj[200];
bool visited[200];
int connected;

void dfs(int node){
    ++connected;
    visited[node] = true;
    for (int next : adj[node]){
        if (!visited[next]){
            dfs(next);
        }
    }
}

// Use fstream (fin, fout) instead of iostream!
void solve(){
    fin >> n;

    vector<Cow> c;
    for (int i = 0; i < n; ++i){
        int x, y, w;
        fin >> x >> y >> w;

        c.pb(Cow(x, y, w));
    }

    for (int i = 0; i < n; ++i){
        int x = c[i].x, y = c[i].y, w = c[i].w;
        for (int ii = 0; ii < n; ++ii){
            if (i == ii){
                continue;
            }

            int a = c[ii].x, b = c[ii].y;
            if ((x - a) * (x - a) + (y - b) * (y - b) <= w * w){
                adj[i].pb(ii);
            }
        }
    }

    int ans = 0;

    for (int i = 0; i < n; ++i){
        connected = 0;
        fill(visited, visited + 200, 0);
        dfs(i);

        ans = max<int>(ans, connected);
    }

    fout << ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    solve();
    return 0;
}