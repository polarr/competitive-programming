/**
 * Solution by 1egend (polarity.sh)
 * Date: 2025-02-02
 * Contest: SAPO 2015
 * Problem: jazz
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

int n;
vi arr;
vector<vi> ans;

int find(int i, int j){
    if (j <= i){
        return 0;
    }

    if (ans[i][j] != -1){
        return ans[i][j];
    }

    int x = arr[i];
    int a = 501;
    rep(t, i + 1, j){
        if (arr[t] == x){
            a = min(a, find(i + 1, t) + find(t + 1, j));
        }
    }

    a = min(a, 1 + find(i + 1, j));

    return ans[i][j] = a;
}

void solve(){
    string s; cin >> s;
    n = s.size();
    arr = vi(n);
    ans = vector<vi>(n, vi(n + 1, -1));
    rep(i, 0, n){
        arr[i] = s[i] - 'a';
    }

    cout << find(0, n) << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}