/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-04-28
 * Contest: DMOJ Spring Coding Bowl 2024
 * Problem: 2
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

void solve(){
    string s;
    cin >> s;
    int n; cin >> n;
    vector<char> rep(26);
    for (int i = 0; i < 26; i++){
        rep[i] = static_cast<char>('a' + i);
    }

    for (int i = 0; i < n; i++){
        char a, b;
        cin >> a >> b;
        for (int j = 0; j < 26; j++){
            if (rep[j] == a){
                rep[j] = b;
            }
        }
    }
    
    for (int i = 0; i < s.size(); i++){
        s[i] = rep[s[i] - 'a'];
    }

    cout << s << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}