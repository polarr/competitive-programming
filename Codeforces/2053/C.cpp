/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-12-28
 * Contest: Codeforces 2053
 * Problem: C
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long
#define sll __int128

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

pair<sll, sll> r(int n, int k){
    if (n < k){
        return {0, 0};
    }

    if (n == 1){
        return {1, 1};
    }

    sll m = (1 + n)/2;

    if (n % 2 == 0){
        pair<sll, sll> p = r(m, k);
        return {2 * p.first + p.second * m, 2 * p.second};
    }

    pair<sll, sll> p = r(m - 1, k);

    return {m + 2 * p.first + p.second * m, 2 * p.second + 1};
}

sll read() {
    sll x = 0, f = 1;
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

void print(sll x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) print(x / 10);
    putchar(x % 10 + '0');
}

void solve(){
    int n, k; cin >> n >> k;

    pair<sll, sll> ans = r(n, k);

    print(ans.first);
    putchar('\n');
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