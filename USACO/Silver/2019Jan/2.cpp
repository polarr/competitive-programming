/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-02-15
 * Contest: USACO 2019 January Contest
 * Problem: Silver - P2. Icy Perimeter
**/

#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;

const string iofilename = "perimeter";
ifstream fin(iofilename + ".in");
ofstream fout(iofilename + ".out");

vector<vector<int>> grid;
int area, perimeter;
int maxArea = 0, minPerimeter = 0;
bool floodfill(int y, int x, int component){
    if (x < 0 || x >= grid.size() || y < 0 || y >= grid.size()){
        return false;
    }

    if (grid[y][x] == component){
        return true;
    }

    if (grid[y][x] != 0){
        return false;
    }

    int perim = 4;
    grid[y][x] = component;
    area++;
    if (floodfill(y + 1, x, component)){
        perim--;
    }

    if (floodfill(y - 1, x, component)){
        perim--;
    }

    if (floodfill(y, x + 1, component)){
        perim--;
    }
    
    if (floodfill(y, x - 1, component)){
        perim--;
    }

    perimeter += perim;

    return true;
}

// Use fstream (fin, fout) instead of iostream!
void solve(){
    int n;
    fin >> n;

    grid = vector<vector<int>> (n);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            char x;
            fin >> x;
            if (x == '#'){
                grid[i].pb(0);
            } else {
                grid[i].pb(-1);
            }
        }
    }

    int component = 1;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            area = 0;
            perimeter = 0;
            if (floodfill(i, j, component)){
                component++;
            }

            if (area == maxArea){
                minPerimeter = min(minPerimeter, perimeter);
            } else if (area > maxArea){
                maxArea = area;
                minPerimeter = perimeter;
            }
        }
    }

    fout << maxArea << " " << minPerimeter;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    solve();
    return 0;
}