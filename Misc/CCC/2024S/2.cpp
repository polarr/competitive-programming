#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

void solve(int n){
    vector<bool> heavy(26, false);
    unordered_set<int> alph;
    string s;
    cin >> s;
    for (int i = 0; i < n; i++){
        int x = s[i] - 'a';
        if (alph.count(x) > 0){
            heavy[x] = true;
            continue;
        }
        alph.insert(x); 
    }

    bool curr = heavy[s[0] - 'a'];
    bool ans = true;
    for (int i = 1; i < n; i++){
        if (heavy[s[i] - 'a'] == curr){
            ans = false;
            break;
        }

        curr = heavy[s[i] - 'a'];
    }

    cout << (ans ? "T":"F") << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t, n;
    cin >> t >> n;
    for (int i = 0; i < t; i++){
        solve(n);
    }
    return 0;
}