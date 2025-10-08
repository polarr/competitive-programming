/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-10-07
 * Contest: 
 * Problem: F_generator
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

const int MAX_N = 1e9;
const ll MOD = 1e9 + 7;

int randInt(int l, int h){
    return rand() % (h - l + 1) + l;
}

void solve(){
}

int main(){
    srand(time(0));

    int n = randInt(1, 20);
    int z = randInt(1, MAX_N);
    cout << n << " ";
    cout << z << endl;
    vi arr(n);
    rep(i, 0, n){
        arr[i] = randInt(1, MAX_N);
    }
    sort(all(arr));
    rep(i, 0, n){
        cout << arr[i] << endl;
    }
    int q = randInt(1, 10);
    cout << q << endl;
    rep(i, 0, q){
        int a = randInt(1, n);
        int b = randInt(1, n);
        cout << min(a, b) << " ";
        cout << max(a, b) << endl;
    }

    return 0;
}