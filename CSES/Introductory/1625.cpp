/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-04-11
 * Contest: CSES Problemset
 * Problem: 1625. Introductory Problems - Grid Paths
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

int ans = 0;

vector<int> cy = {-1, 0, 1, 0};
vector<int> cx = {0, 1, 0, -1};

vector<int> pre;
vector<vector<bool>> visited = vector<vector<bool>>(9, vector<bool>(9, false));

void generate(int y, int x, int move){
    if (move == 48){
        if (x == 1 && y == 7){
            ans++;
        }
        return;
    }

    if (x == 1 && y == 7){
        return;
    }

    // cannot move forward but can move to other two directions. creates two disjoint components and fails
    if ((!visited[y + 1][x] && !visited[y - 1][x]) && (visited[y][x + 1] && visited[y][x - 1])){
        return;
    }

    if ((visited[y + 1][x] && visited[y - 1][x]) && (!visited[y][x + 1] && !visited[y][x - 1])){
        return;
    }

    visited[y][x] = true;
    int dir = pre[move];

    if (dir == 4){
        if (!visited[y - 1][x]) generate(y - 1, x, move + 1);
        if (!visited[y + 1][x]) generate(y + 1, x, move + 1);
        if (!visited[y][x - 1]) generate(y, x - 1, move + 1);
        if (!visited[y][x + 1]) generate(y, x + 1, move + 1);
    }
    else {
        if (!visited[y + cy[dir]][x + cx[dir]]) generate(y + cy[dir], x + cx[dir], move + 1);
    }
    visited[y][x] = false;
}

void solve(){
    string path;
    cin >> path;

    for (int i = 0; i < path.size(); i++){
        char m = path[i];
        if (m == '?'){
            pre.pb(4);
            continue;
        }

        if (m == 'U') pre.pb(0);
        else if (m == 'R') pre.pb(1);
        else if (m == 'D') pre.pb(2);
        else pre.pb(3);
    }

    for (int i = 0; i < 9; i++){
        visited[i][0] = true;
        visited[i][8] = true;
        visited[0][i] = true;
        visited[8][i] = true;
    }

    generate(1, 1, 0);

    cout << ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}