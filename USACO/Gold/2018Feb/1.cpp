/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-02-12
 * Contest: USACO 2018 February
 * Problem: Gold P1. Snow Boots
**/

// Unfinished

#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;

const string iofilename = "snowboots";
ifstream fin(iofilename + ".in");
ofstream fout(iofilename + ".out");

// Use fstream (fin, fout) instead of iostream!
void solve(){
    int n, b;
    fin >> n >> b;
    vector<int> tiles;
    for (int i = 0; i < n; i++){
        int f;
        fin >> f;
        tiles.pb(f);
    }

    for (int i = 0; i < b; i++){
        int s, d;
        fin >> s >> d;

        bool can = true;
        int curr = 0;
        int next = 1;
        while (next < n - 1){
            if (tiles[next] <= s){
                curr = next;
            }

            next++;
            if (next > curr + d){
                fout << 0 << endl;
                can = false;
                break;
            }
        }

        if (can){
            fout << 1 << endl;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    solve();
    return 0;
}