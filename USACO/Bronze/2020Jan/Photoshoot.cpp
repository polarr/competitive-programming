/**
 * Solution by 1egend
 * Date: 7/8/2021
 * Contest: USACO 2020 January Contest
 * Problem: Bronze P2. Photoshoot
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

const string iofilename = "photo";
ifstream fin(iofilename + ".in");
ofstream fout(iofilename + ".out");

// Use fstream (fin, fout) instead of iostream!
void solve(){
    int n;
    fin >> n;
    vector <int> bs;
    for (int i = 0; i < n - 1; ++i){
        static int t;
        fin >> t;

        bs.pb(t);
    }

    for (int i = 1; i < bs[0]; ++i){
        set <int> ns{i};
        vector <int> ans{i};
        int next = i;
        bool broken = false;
        for (int k = 0; k < n - 1; ++k){
            next = bs[k] - next;
            if (ns.count(next) != 0 || next <= 0){
                broken = true;
                break;
            }
            
            ns.insert(next);
            ans.pb(next);
        }

        if (broken){
            continue;
        }

        for (int z = 0; z < n - 1; ++z){
            fout << ans[z] << " ";
        }

        fout << ans[n - 1];
        break;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    solve();
    return 0;
}