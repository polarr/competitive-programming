/**
 * Solution by 1egend
 * Date: 7/12/2021
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

// Use fstream (fin, fout) instead of iostream!
void solve(){
    int n;
    fin >> n;

    vector <pair<int, int>> mountains;
    for (int i = 0; i < n; ++i){
        static int a, b;
        fin >> a >> b;

        mountains.pb(mp(a - b, a + b));
    }

    int ans = n;
    for (int a = 0; a < n; ++a){
        for (int b = 0; b < n; ++b){
            if (a == b){
                continue;
            }

            if (mountains[b].first <= mountains[a].first && mountains[b].second >= mountains[a].second){
                --ans;
                break;
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