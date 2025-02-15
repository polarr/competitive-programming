/**
 * Solution by 1egend (polarity.sh)
 * Date: 2025-02-14
 * Contest: Baltic OI 2016
 * Problem: swap
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

const int MAX_N = 2e5 + 1;
const ll MOD = 1e9 + 7;

// O(n logn) space
// Since I'm lazy use a map for O(n (logn)^2)
vector<map<int, int>> dp;
vi tree;
int nn = 1;

/** THIS DOES NOT WORK SINCE THE "end up" position of a value in a subtree root is not monotonic 
 * But easy fix, just ditch the binary sort and DP directly, only logn values of subtree roots possible, and you only need to compare end up positions to determine optimal allocation (very trivial)
 * O(n logn)
*/

// Since I'm lazy use a map for O(n (logn)^2)
int rec(int node, int x){   
    if (dp[node][x] != 0){
        return dp[node][x];
    } 

    if (node >= nn/2){
        // leaf
        return dp[node][x] = node;
    }

    int a = node * 2, b = node * 2 + 1;
    int aa = tree[a], bb = tree[b];

    if (x < aa && x < bb){
        return dp[node][x] = node;
    }

    if (aa < bb){
        return dp[node][x] = rec(a, x);
    }

    if (x < aa){
        return dp[node][x] = min(rec(a, x), rec(b, x));
    }

    int p1 = rec(a, aa), p2 = rec(b, aa);
    if (p1 < p2){
        return dp[node][x] = rec(b, x);
    }

    return dp[node][x] = rec(a, x);
}

void extract(int node){
    if (node >= nn/2){
        // leaf
        return;
    }

    int x = tree[node];

    int a = node * 2, b = node * 2 + 1;
    int aa = tree[a], bb = tree[b];

    if (x < aa && x < bb){
        extract(a); extract(b);
        return;
    }

    if (aa < bb){
        tree[node] = aa;
        tree[a] = x;
        extract(a); extract(b);
        return;
    }

    tree[node] = bb;

    int p = min(x, aa), q = max(x, aa);

    if (rec(a, p) < rec(b, p)){
        tree[a] = p;
        tree[b] = q;
    } else {
        tree[a] = q;
        tree[b] = p;
    }

    extract(a); extract(b);
}

void solve(){
    int n; cin >> n;
    while(nn <= n){
        nn *= 2;
    }

    tree = vi(nn, MAX_N);
    dp = vector<map<int, int>>(nn);

    rep(i, 0, n){
        cin >> tree[i + 1];
    }

    extract(1);

    rep(i, 1, n + 1){
        cout << tree[i] << " ";
    }

    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}