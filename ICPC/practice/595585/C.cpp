/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-03-12
 * Contest: Codeforces ICPC Practice 595585
 * Problem: C
**/

#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using pii = pair<int, int>;
#define pb push_back
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

void solve(){
    int n; cin >> n;

    vector<vi> words(n);

    rep(i, 0, n){
        string s; cin >> s;
        rep(j, 0, s.size()){
            words[i].pb(s[j] - 'a');
        }
    }

    string t; cin >> t;
    vi match; 

    rep(i, 0, t.size()){
        match.pb(t[i] - 'a');
    }

    vector<string> ans(t.size(), "");
    bool can = true;
    int idx = 0;
    rep(i, 0, n){
        vi word = words[i];

        int m = 0;

        rep(j, 0, word.size()){
            if (word[j] == match[m]){
                m++;
            } else {
                ans[m] += ('a' + word[j]);
            }

            if (m == match.size()){
                can = false;
                break;
            }
        }
        
        if (!can){
            cout << "NO" << endl;
            return;
        }
    }


    string rans = "";

    rep(i, 0, ans.size()){
        rans += ans[i];
        if (i != ans.size() - 1) rans += ('a' + match[i]);
    }

    cout << "YES" << endl;
    cout << rans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}