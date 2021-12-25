/**
 * Solution by 1egend
 * Date: 2021-12-17
 * Contest: USACO 2021 December Contest
 * Problem: Bronze P1. Lonely Photo
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
    int n; string s;
    cin >> n >> s;

    set<int> g;
    set<int> h;
    for (int i = 0; i < n; ++i){
        if (s[i] == 'G'){
            g.insert(i);
        } else {
            h.insert(i);
        }
    }

    ll ans = 0;
    for (int i = 0; i <= n - 3; ++i){
        set<int>::iterator nexta, finala, firstb, secondb, finalb;
        if (s[i] == 'G'){
            nexta = g.upper_bound(i);
            firstb = h.upper_bound(i);
            secondb = h.upper_bound(*firstb);
            finala = g.end();
            finalb = h.end();
        }
        else {
            nexta = h.upper_bound(i);
            firstb = g.upper_bound(i);
            secondb = g.upper_bound(*firstb);
            finala = h.end();
            finalb = g.end();
        }

        if (nexta == finala){
            ans += n - i - 2;
            continue;
        }

        if (*nexta - i >= 3){
            ans += *nexta - i - 2;
            continue;
        }

        if (firstb == finalb){
            continue;
        }

        if (secondb == finalb){
            ans += n - max<int>(*firstb, i + 2);
            continue;
        }

        ans += *secondb - max<int>(*firstb, i + 2);
    }

    cout << ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    solve();
    return 0;
}