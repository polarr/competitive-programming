/**
 * Solution by 1egend
 * Date: 7/15/2021
 * Contest: USACO 2015 December Contest
 * Problem: Silver - P2. High Card Wins
**/

#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;

const string iofilename = "highcard";
ifstream fin(iofilename + ".in");
ofstream fout(iofilename + ".out");

// Use fstream (fin, fout) instead of iostream!
void solve(){
    int n;
    fin >> n;

    set <int> bessie;
    vector <int> elsie;

    for (int i = 0; i < 2 * n; ++i){
        bessie.insert(i + 1);
    }


    for (int i = 0; i < n; ++i){
        static int t;
        fin >> t;
        elsie.pb(t);
        bessie.erase(t);
    }

    int ans = 0;
    for (int i = 0; i < n; ++i){
        if (elsie[i] > *(--bessie.end())){
            // bessie.erase(bessie.begin());
            continue;
        }

        ++ans;
        bessie.erase(bessie.upper_bound(elsie[i]));
    }

    fout << ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    solve();
    return 0;
}