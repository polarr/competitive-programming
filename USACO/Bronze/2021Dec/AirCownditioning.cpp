/**
 * Solution by 1egend
 * Date: 2021-12-17
 * Contest: USACO 2021 December Contest
 * Problem: Bronze 
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

// Use fstream (fin, fout) instead of iostream!
void solve(){
    int n;
    cin >> n;

    vector<int> stalls;
    for (int i = 0; i < n; ++i){
        int a;
        cin >> a;

        stalls.pb(a);
    }

    for (int i = 0; i < n; ++i){
        int b;
        cin >> b;
        stalls[i] -= b;
    }

    int ans = 0;
    int t = -1;
    while(t != n - 1){
        if (stalls[t + 1] == 0){
            ++t;
            continue;
        }

        int i = t + 1;
        int ext = INT_MAX;
        bool positive = (stalls[i] > 0);
        while(stalls[i] != 0 && positive == (stalls[i] > 0)){
            ext = min<int>(ext, abs(stalls[i]));
            ++i;
        }

        for (int ii = t + 1; ii < i; ++ii){
            if (positive){
                stalls[ii] -= ext;
                continue;
            }

            stalls[ii] += ext;
        }
        ans += ext;
    }

    cout << ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    solve();
    return 0;
}