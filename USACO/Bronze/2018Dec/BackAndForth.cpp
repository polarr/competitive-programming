/**
 * Solution by 1egend
 * Date: 7/10/2021
 * Contest: USACO 2018 December Contest
 * Problem: Bronze - P3. Back and Forth
**/

#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;

const string iofilename = "backforth";
ifstream fin(iofilename + ".in");
ofstream fout(iofilename + ".out");

vector<int> a, b;
int countPerm(int p, int q, int r, int s){
    vector <int> dummyA = a;
    vector <int> dummyB = b;

    int total = 1000;
    total -= dummyA[p];
    dummyB.pb(dummyA[p]);
    dummyA.erase(dummyA.begin() + p);

    total += dummyB[q];
    dummyA.pb(dummyB[q]);
    dummyB.erase(dummyB.begin() + q);

    total -= dummyA[r];
    dummyB.pb(dummyA[r]);
    dummyA.erase(dummyA.begin() + r);

    total += dummyB[s];
    return total;
}

// Use fstream (fin, fout) instead of iostream!
void solve(){
    for (int i = 0; i < 10; ++i){
        static int t; fin >> t;
        a.pb(t);
    }

    for (int i = 0; i < 10; ++i){
        static int t; fin >> t;
        b.pb(t);
    }

    set <int> possible;
    for (int p = 0; p < 10; ++p){
        for (int q = 0; q < 11; ++q){
            for (int r = 0; r < 10; ++r){
                for (int s = 0; s < 11; ++s){
                    int total = countPerm(p, q, r, s);
                    possible.insert(total);
                }
            }
        }
    }

    int ans = 0;
    for (auto i:possible){
        ++ ans;
    }

    fout << ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    solve();
    return 0;
}