/**
 * Solution by 1egend
 * Date: 2021-12-20
 * Contest: USACO 2021 December
 * Problem: Silver 
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

ull mx(int start, int end, vector<pair<int, int>> grass){
    ull ans = 0;
    for (double i = start + 0.5; i < end; ++i){
        ull temp = 0;
        for (int g = 0; g < grass.size(); ++g){
            int pos = grass[g].first;
            if (abs(i - pos) > abs(pos - start) && abs(i - pos) > abs(pos - end)){
                temp += grass[g].second;
            }
        }

        ans = max<ull>(ans, temp);
    }

    return ans;
}

// Use fstream (fin, fout) instead of iostream!
void solve(){
    int k, m, n;
    cin >> k >> m >> n;

    vector<pair<int, int>> grass;
    vector<int> f;
    for (int i = 0; i < k; ++i){
        int a, b; cin >> a >> b;
        grass.pb(mp(a, b));
    }

    for (int i = 0; i < m; ++i){
        int t; cin >> t;
        f.pb(t);
    }

    sort(grass.begin(), grass.end());
    sort(f.begin(), f.end());

    int c = 0;
    int g = 0;
    vector<int> dtastiness(c + 1);
    vector<int> stastiness(c + 1);
    vector<pair<int, int>> temp;
    while(c < m + 1){
        if (grass[g].first < f[c]){
            dtastiness[c] += grass[g].second;
            ++g;

            temp.pb(grass[g]);
            continue;
        }

        stastiness[c] = mx(c == 0 ? -1: f[c - 1], f[c], temp);
        dtastiness[c] -= stastiness[c];
        temp = {};
        ++c;
    }

    vector<int> s = tastiness;
    sort(s.end(), s.begin());
    
    while(n > 1){

        n -= 2;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    solve();
    return 0;
}