/**
 * Solution by 1egend
 * Date: 7/9/2021
 * Contest: USACO 2919 December Contest 
 * Problem: Bronze - P2. Where Am I?
**/

#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;

const string iofilename = "whereami";
ifstream fin(iofilename + ".in");
ofstream fout(iofilename + ".out");

// Use fstream (fin, fout) instead of iostream!
void solve(){
    int n;
    string road;
    fin >> n >> road;

    for (int i = 1; i <= n; ++i){
        unordered_set <string> sequences;
        bool sol = true;
        for (int k = 0; k <= n - i; ++k){
            string sequence = road.substr(k, i);
            if (sequences.count(sequence) > 0){
                sol = false;
                break;
            }

            sequences.insert(sequence);
        }

        if (sol){
            fout << i;
            break;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
    return 0;
}