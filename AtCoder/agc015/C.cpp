/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-01-26
 * Contest: AtCoder Grand Contest 015
 * Problem: C
**/

// Not correct, solves for # of overall connected component representation in the region rather than # of connected components in the region when cut off from everything else

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

vector<vector<int>> grid;
vector<vector<int>> component;
vector<vector<unordered_set<int>>> cs;

int current = 1;
bool floodfill(int i, int j){
    if (i < 0 || j < 0 || i >= grid.size() || j >= grid[i].size() || component[i][j] != -1){
        return false;
    }

    if (grid[i][j] == 0){
        component[i][j] = 0;
        return false;
    }

    component[i][j] = current;
    floodfill(i, j + 1);
    floodfill(i, j - 1);
    floodfill(i + 1, j);
    floodfill(i - 1, j);
    return true;
}

void solve(){
    int n, m, q;
    cin >> n >> m >> q;

    grid = vector<vector<int>>(n, vector<int>(m));
    component = vector<vector<int>>(n, vector<int>(m, -1));
    cs = vector<vector<unordered_set<int>>>(n + 1, vector<unordered_set<int>>(m + 1));
    vector<vector<int>> prefix(n + 1, vector<int>(m + 1));

    for (int i = 0; i < n; i++){
        string s; cin >> s;
        for (int j = 0; j < m; j++){
            grid[i][j] = s[j] - '0';
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (floodfill(i, j)){
                current++;
            }
        }
    }
    /**
    for (vector<int> i : component){
        for (int j : i){
            cout << j << " ";
        }
        cout << endl;
    }
    */
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            unordered_set<int> temp = cs[i - 1][j];
            for (int x : cs[i][j - 1]){
                temp.insert(x);
            }
            if (component[i - 1][j - 1] != 0){
                temp.insert(component[i - 1][j - 1]);
            }
            cs[i][j] = temp;
            prefix[i][j] = temp.size();
        }
    }
    /**
    for (vector<int> i : prefix){
        for (int j : i){
            cout << j << " ";
        }
        cout << endl;
    }
    */
    vector<vector<int>> connectX(n + 1, vector<int>(m + 1, 0));
    vector<vector<int>> connectY(n + 1, vector<int>(m + 1, 0));
    
    for (int i = 2; i < n + 1; i++){
        //unordered_set<int> connect;
        int connect = 0;
        for (int j = 1; j < m + 1; j++){
            if (grid[i - 1][j - 1] == 1 && grid[i - 2][j - 1] == 1){
                //connect.insert(component[i - 1][j - 1]);
                connect++;
            }
            connectX[i][j] = connect;
        }
    }

    for (int j = 2; j < m + 1; j++){
        //unordered_set<int> connect;
        int connect = 0;
        for (int i = 1; i < n + 1; i++){
            if (grid[i - 1][j - 1] == 1 && grid[i - 1][j - 2] == 1){
                //connect.insert(component[i - 1][j - 1]);
                connect++;
            }
            connectY[i][j] = connect;
        }
    }

    for (vector<int> i : connectX){
        for (int j : i){
            cout << j << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < q; i++){
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        cout << prefix[r2][c2] - prefix[r2][c1 - 1] - prefix[r1 - 1][c2] + prefix[r1 - 1][c1 - 1] + connectX[r1][c2] - connectX[r1][c1 - 1] + connectY[r2][c1] - connectY[r1 - 1][c1] << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
    return 0;
}