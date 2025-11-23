/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-11-22
 * Contest: 
 * Problem: A
**/

#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = __int128;
using vi = vector<int>;
using vl = vector<ll>;
using pii = pair<int, int>;
#define pb push_back
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

ll read() {
    ll x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}

void print(ll x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) print(x / 10);
    putchar(x % 10 + '0');
}

void solve(){
    ll n, k;
    n = read();
    k = read();

    ll tot = (n * (n - 1))/2;

    ll a, b;
    a = read();
    b = read();
    ll lo = 1, hi = a * 9e18;

    auto count = [&](ll y, ll x) -> ll {
        return (y - x)/2;
    };

    while (lo < hi) {
        ll d = (lo + hi)/2;
        ll x = 1;
        ll cnt = 0;
        while (x < n) {
            if (d/x - b * 2 <= 0) break;
            ll y = (d/x - b * 2)/a;
            
            y = min(y, n * 2 - x);
            if (y <= x) break;
            cnt += count(y, x);
            if (cnt >= k) break;
            x++;
        }

        if (cnt >= k) {
            hi = d;
        } else {
            lo = d + 1;
        }
    }

    ll g = __gcd(a, lo);
    print(lo/g);
    putchar(' ');
    print(a/g);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}