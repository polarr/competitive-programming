/**
 * Solution by 1egend
 * Date:
 * Contest: WOSS
 * Problem:
 **/

#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;

const string iofilename = "";
ifstream fin(iofilename + ".in");
ofstream fout(iofilename + ".out");

int n, m;
int tempans = 0;
vector<pair<pair<int, int>, pair<int, int>>> teleport(26, mp(mp(-1, -1), mp(-1, -1)));
int grid[200][200];
vector <pair<int, int>> goals(5);
int dist[200][200];

void bfs(int r, int c, int gr, int gc)
{
    memset( &dist[0][0], -1, sizeof(dist) );
    queue<pair<int, int>> q;
    dist[r][c] = 0;
    q.push(mp(r, c));
    while (!q.empty())
    {
        pair<int, int> v = q.front();
        q.pop();
        vector<pair<int, int>> adj;
        if (grid[v.first - 1][v.second]){
            adj.pb(mp(v.first - 1, v.second));
        }
        if (grid[v.first + 1][v.second]){
            adj.pb(mp(v.first + 1, v.second));
        }
        if (grid[v.first][v.second - 1]){
            adj.pb(mp(v.first, v.second - 1));
        }
        if (grid[v.first][v.second + 1]){
            adj.pb(mp(v.first, v.second + 1));
        }
        for (pair<int, int> e : adj)
        {
            if (dist[e.first][e.second] == -1)
            {   
                
                dist[e.first][e.second] = dist[v.first][v.second] + 1;
                for (int i = 0; i < 26; ++i){
                    if (e == teleport[i].first){
                        e = teleport[i].second;
                        dist[e.first][e.second] = dist[v.first][v.second] + 1;
                        break;
                    }
                }
                if (e.first == gr && e.second == gc){
                    tempans = dist[e.first][e.second];
                    return;
                }
                q.push(e);
            }
        }
    }
}

// Use fstream (fin, fout) instead of iostream!
void solve()
{
    cin >> m >> n;
    for (int c = 0; c < n; ++c){
        for (int r = 0; r < m; ++r){
            char t;
            cin >> t;
            if (t == '.'){
                grid[c][r] = 1;
            } else if (t == '#'){
                grid[c][r] = 0;
            } else if (isdigit(t)){
                goals[(int)(t)] = mp(c, r);
                grid[c][r] = 1;
            } else if (isalpha(t)){
                int x = t - 'a';
                if (x < 26){
                    teleport[x].second = mp(c, r);
                    grid[c][r] = 0;
                } else {
                    teleport[x].first = mp(c, r);
                    grid[c][r] = 1;
                }
            }
        }
    }

    int ans = 0;
    
    for (int i = 0; i < 4; ++i){
        tempans = 0;
        pair<int, int> current = goals[i];
        pair<int, int> goal = goals[i + 1];

        bfs(current.first, current.second, goal.first, goal.second);
        if (tempans == 0){
            cout << "-1";
            return;
        }
        ans += tempans;
    }

    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();
    return 0;
}