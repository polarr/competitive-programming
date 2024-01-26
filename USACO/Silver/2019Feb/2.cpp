/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-01-23
 * Contest: USACO 2019 February Contest
 * Problem: Silver P2. Painting the Barn
**/

#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;

const string iofilename = "paintbarn";
ifstream fin(iofilename + ".in");
ofstream fout(iofilename + ".out");

vector<vector<int>> barn(1000, vector<int>(1000, 0));
vector<vector<int>> area(1000, vector<int>(1000, 0));

// Use fstream (fin, fout) instead of iostream!
void solve(){
    int n, k;
    fin >> n >> k;

    for (int i = 0; i < n; i++){
        int x1, y1, x2, y2;
        fin >> x1 >> y1 >> x2 >> y2;

        barn[x1][y1]++;
        barn[x2][y2]++;
        barn[x1][y2]--;
        barn[x2][y1]--;
    }

    int ans = 0;

    for (int i = 0; i < 1000; i++){
        for (int j = 0; j < 1000; j++){
            area[i][j] += barn[i][j];
            if (j > 0){
                area[i][j] += area[i][j - 1];
            }
            if (i > 0){
                area[i][j] += area[i - 1][j];
            }
            if (i > 0 && j > 0){
                area[i][j] -= area[i - 1][j - 1];
            }

            if (area[i][j] == k){
                ans++;
            }
        }
    }

    fout << ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    solve();
    return 0;
}