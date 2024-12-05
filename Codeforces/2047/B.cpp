/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-12-02
 * Contest: Codeforces 2047
 * Problem: B
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    vector<int> alph(26, 0);
    int numChanged = 0;

    int mn = INT_MAX;
    int mna = -1;
    int mx = -1;
    int mxa = -1;

    for (int i = 0; i < n; i++){
        int t = s[i] - 'a';
        if (alph[t] == 0){
            numChanged++;
        }
        alph[t]++;
    }

    int seconda = -1;

    for (int i = 0; i < n; i++){
        int t = s[i] - 'a';
        if (alph[t] < mn){
            mn = alph[t];
            mna = i;
        }

        if (alph[t] > mx){
            mx = alph[t];
            mxa = i;
        }

        if (t != s[0] - 'a'){
            seconda = i;
        }
    }

    if (numChanged == 1){
        cout << s << endl; 
        return;
    }

    if (mna == mxa){
        s[0] = s[seconda];
        cout << s << endl;
        return;
    }
    
    s[mna] = s[mxa];
    cout << s << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for (int t = 1; t <= tc; ++t){
        // cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}