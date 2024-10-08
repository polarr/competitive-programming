/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-10-05
 * Contest: ICPC NAQ 2024
 * Problem: I
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
    int n; cin >> n;

    vector<vector<char>> grid(n + 2, vector<char>(n + 2, 'X'));
    vector<vector<bool>> visited(n + 2, vector<bool>(n + 2, false));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            char s; cin >> s;
            grid[i + 1][j + 1] = s;
        }
    }

    for (int i = 1; i < n + 1; i++){
        for (int j = 1; j < n + 1; j++){
            char s = grid[i][j];
            // check if number cells have property
            if (s == '0' || s == '1' || s == '2' || s == '3' || s == '4'){
                int num = s - '0';
                int cc = 0;
                for (int x = 0; x < 4; x++){
                    pair<int, int> c = cardinal[x];
                    if (grid[i + c.first][j + c.second] == '?'){
                        cc++;
                    }
                }

                if (cc != num){
                    cout << 0 << endl;
                    return;
                }
            }
        }
    }

    for (int i = 0; i < n + 2; i++){
        for (int j = 0; j < n + 2; j++){
            char s = grid[i][j];
            if (s == '?'){
                for (int x = j + 1; x < n + 2; x++){
                    char ss = grid[i][x];
                    if (ss == '.'){
                        visited[i][x] = true;
                    }
                    else if (ss == '?'){
                        cout << 0 << endl;
                        return;
                    }
                    else{
                        break;
                    }
                }

                for (int x = j - 1; x >= 0; x--){
                    char ss = grid[i][x];
                    if (ss == '.'){
                        visited[i][x] = true;
                    }
                    else if (ss == '?'){
                        cout << 0 << endl;
                        return;
                    }
                    else{
                        break;
                    }
                }

                for (int y = i - 1; y >= 0; y--){
                    char ss = grid[y][j];
                    if (ss == '.'){
                        visited[y][j] = true;
                    }
                    else if (ss == '?'){
                        cout << 0 << endl;
                        return;
                    }
                    else{
                        break;
                    }
                }

                for (int y = i + 1; y < n + 2; y++){
                    char ss = grid[y][j];
                    if (ss == '.'){
                        visited[y][j] = true;
                    }
                    else if (ss == '?'){
                        cout << 0 << endl;
                        return;
                    }
                    else{
                        break;
                    }
                }
            }
        }
    }

    for (int i = 0; i < n + 2; i++){
        for (int j = 0; j < n + 2; j++){
            if (!visited[i][j] && grid[i][j] == '.'){
                cout << 0 << endl;
                return;
            }
        }
    }

    cout << 1 << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}