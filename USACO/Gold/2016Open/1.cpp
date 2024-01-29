/**
 * Solution by 1egend
 * Date: 2024-01-29
 * Contest: USACO 2016 Open
 * Problem: Gold P1. Splitting the Field
**/

#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;

const string iofilename = "split";
ifstream fin(iofilename + ".in");
ofstream fout(iofilename + ".out");

// Use fstream (fin, fout) instead of iostream!
void solve(){
    int n; fin >> n;
    vector<pair<int, int>> xCows;
    vector<pair<int, int>> yCows;
    int minX = INT_MAX, maxX = 0, minY = INT_MAX, maxY = 0;
    for (int i = 0; i < n; i++){
        int x, y;
        fin >> x >> y;
        minX = min(minX, x);
        maxX = max(maxX, x);
        minY = min(minY, y);
        maxY = max(maxY, y);
        xCows.pb(make_pair(x, y));
        yCows.pb(make_pair(y, x));
    }

    ull oneArea = (ull)(maxX - minX) * (maxY - minY);

    sort(xCows.begin(), xCows.end());
    sort(yCows.begin(), yCows.end());

    set<int> canX;
    set<int> canY;
    for (int i = 0; i < n - 1; i++){
        if (xCows[i + 1].first != xCows[i].first){
            canX.insert(i);
        }
        if (yCows[i + 1].first != yCows[i].first){
            canY.insert(i);
        }
    }

    vector<ull> xCowsMaxStart(n, 0);
    vector<ull> xCowsMaxReverse(n, 0);
    vector<ull> yCowsMaxStart(n, 0);
    vector<ull> yCowsMaxReverse(n, 0);
    int xMax = xCows[0].second;
    int xMin = xCows[0].second;
    int yMax = yCows[0].second;
    int yMin = yCows[0].second;
    for (int i = 1; i < n; i++){
        xMax = max(xMax, xCows[i].second);
        xMin = min(xMin, xCows[i].second);
        yMax = max(yMax, yCows[i].second);
        yMin = min(yMin, yCows[i].second);
        xCowsMaxStart[i] = xMax - xMin;
        yCowsMaxStart[i] = yMax - yMin;
    }

    xMax = xCows[n - 1].second;
    xMin = xCows[n - 1].second;
    yMax = yCows[n - 1].second;
    yMin = yCows[n - 1].second;

    for (int i = n - 2; i >= 0; i--){
        xMax = max(xMax, xCows[i].second);
        xMin = min(xMin, xCows[i].second);
        yMax = max(yMax, yCows[i].second);
        yMin = min(yMin, yCows[i].second);
        xCowsMaxReverse[i] = xMax - xMin;
        yCowsMaxReverse[i] = yMax - yMin;
    }

    ull twoArea = ULLONG_MAX;
    for (int i : canX){
        twoArea = min(twoArea, (ull)(xCows[i].first - minX) * xCowsMaxStart[i] + 
        (maxX - xCows[i + 1].first) * xCowsMaxReverse[i + 1]);
    }

    for (int i : canY){
        twoArea = min(twoArea, (ull)(yCows[i].first - minY) * yCowsMaxStart[i] + 
        (maxY - yCows[i + 1].first) * yCowsMaxReverse[i + 1]);
    }

    fout << oneArea - min(oneArea, twoArea) << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    fin.tie(0); cout.tie(0);
    
    solve();
    return 0;
}