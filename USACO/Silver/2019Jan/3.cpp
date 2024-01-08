/**
 * Solution by 1egend
 * Date: 1/7/2024
 * Contest: USACO 2019 January Contest
 * Problem: Silver - P3. Mountain View
**/

#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;

const string iofilename = "mountains";
ifstream fin(iofilename + ".in");
ofstream fout(iofilename + ".out");

bool cmp(pair<int, int> a, pair<int, int> b){
    if (a.first + a.second < b.first + b.second){
        return true;
    }

    if (a.first + a.second == b.first + b.second){
        return a.second - a.first > b.second - b.first;
    }

    return false;
}

// Use fstream (fin, fout) instead of iostream!
void solve(){
    int n;
    fin >> n;

    vector<pair<int, int>> m;

    for (int i = 0; i < n; ++i){
        int x, y;
        fin >> x >> y;
        m.pb(mp(y, x));
    }

    sort(m.begin(), m.end(), cmp);
    vector<int> minDiff(n, 0);
    int currentMin = m[n - 1].second - m[n - 1].first;
    minDiff[n - 1] = currentMin;
    int ans = 1;
    for (int i = n - 2; i >= 0; --i){
        int current = m[i].second - m[i].first;
        if (current < currentMin){
            ++ans;
            currentMin = current;
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