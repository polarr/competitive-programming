/**
 * Solution by 1egend (polarity.sh)
 * Date: 2025-01-14
 * Contest: Codeforces 1483
 * Problem: C
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

struct Tree {
    typedef ll T;
    static constexpr T unit = LLONG_MIN;
    T f(T a, T b) { return max(a, b); } // (any associative fn )
    vector<T> s; int n;
    Tree(int n = 0, T def = unit) : s(2*n, def), n(n) {}
    void update(int pos, T val) {
        for (s[pos += n] = val; pos /= 2;)
        s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
    }
    T query(int b, int e) { // query [ b , e)
        T ra = unit, rb = unit;
        for (b += n, e += n; b < e; b /= 2, e /= 2) {
            if (b % 2) ra = f(ra, s[b++]);
            if (e % 2) rb = f(s[--e], rb);
        }
        return f(ra, rb);
    }
};

void solve(){
    int n; cin >> n;
    vector<ll> h(n);
    vector<ll> b(n);
    for (int i = 0; i < n; i++){
        cin >> h[i];
    }
    for (int i = 0; i < n; i++){
        cin >> b[i];
    }

    vector<ll> dp(n + 1, 0);
    stack<pair<ll, int>> mse;
    Tree mx(n);
    dp[0] = 0;
    for (int i = 0; i < n; i++){
        ll height = h[i];
        ll beauty = b[i];
        int last = -1;
        while(!mse.empty()){
            pair<ll, int> t = mse.top();
            if (t.first < height){
                last = t.second;
                break;
            }
            
            mse.pop();
        }

        if (last == -1){
            dp[i + 1] = max(0LL, mx.query(0, i)) + beauty;
        } else {
            dp[i + 1] = max(dp[1 + last], mx.query(last, i) + beauty);
        }

        mse.push({height, i});
        mx.update(i, dp[i + 1]);
    }

    cout << dp[n] << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}