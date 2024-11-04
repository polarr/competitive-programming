/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-11-03
 * Contest: CSES Problemset - Graph Algorithms
 * Problem: 1193
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

vector<pair<int, int>> cardinal = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void solve(){
    int n, m; cin >> n >> m;
    vector<vector<int>> grid(n + 2, vector<int>(m + 2, 0));
    vector<vector<int>> parent = grid;

    pair<int, int> s, e;

    for (int i = 0; i < n; i++){
        string str; cin >> str;
        for (int j = 0; j < m; j++){
            char x = str[j];
            if (x != '#'){
                grid[i + 1][j + 1] = 1;
                if (x == 'A'){
                    s = {i + 1, j + 1};
                }
                else if (x == 'B'){
                    e = {i + 1, j + 1};
                }
            }
        }
    }

    queue<pair<int, int>> q;
    q.push(s);

    bool hasAns = false;

    while(!q.empty()){
        pair<int, int> p = q.front();
        if (p.first == e.first && p.second == e.second){
            hasAns = true;
            break;
        }

        q.pop();
        for (int i = 0; i < 4; i++){
            pair<int, int> t = cardinal[i];
            pair<int, int> x = {p.first + t.first, p.second + t.second};
            if (grid[x.first][x.second] == 0 || parent[x.first][x.second] != 0){
                continue;
            }

            parent[x.first][x.second] = i + 1;
            q.push(x);
        }
    }

    if (!hasAns){
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;

    pair<int, int> curr = e;
    string ans = "";

    while(curr.first != s.first || curr.second != s.second){
        string a = "";
        int c = 0;

        int k = parent[curr.first][curr.second];

        if (k == 1){
            a = "R";
            c = 1;
        } else if (k == 2){
            a = "L";
            c = 0;
        } else if (k == 3){
            a = "D";
            c = 3;
        } else {
            a = "U";
            c = 2;
        }

        ans += a;

        curr = {curr.first + cardinal[c].first, curr.second + cardinal[c].second};
    }
    
    reverse(ans.begin(), ans.end());

    cout << ans.length() << endl;
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}