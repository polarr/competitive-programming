/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-01-07
 * Contest: USACO 2015 December Contest
 * Problem: Silver - 2. High Card Wins
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

    unordered_set <int> elsie;
    for (int i = 0; i < n; i++){
        int x; 
        fin >> x;
        elsie.insert(x);
    }

    set <int> bessie;
    for (int i = 1; i <= 2 * n; i++){
        if (elsie.count(i) == 0){
            bessie.insert(i);
        }
    }

    int ans = 0;
    for (int element : elsie){
        if (bessie.upper_bound(element) == bessie.end()){
            continue;
        }

        bessie.erase(bessie.upper_bound(element));
        ++ans;
    }

    fout << ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    solve();
    return 0;
}