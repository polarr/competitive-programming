/**
 * Solution by 1egend
 * Date:
 * Contest: WOSS Dual Olympiad 
 * Problem:
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
    vector<char> a;
    for (int i = 0; i < 10; ++i){
        char t;
        cin >> t;
        a.pb(t);
    }

    int n;
    cin >> n;

    string ans = "";
    for (int i = 0; i < n; ++i){
        int t;
        cin >> t;
        ans += a[t];
    }

    cout << ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    solve();
    return 0;
}