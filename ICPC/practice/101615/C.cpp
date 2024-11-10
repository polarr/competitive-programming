/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-11-09
 * Contest: ICPC Practice Codeforces 101615
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
    sll a, b; a = read(); b = read();
 
    sll mx = pow(10, 12);
 
    auto cons_sum = [&](sll s, sll e){
        return e * (e + 1)/2 - s * (s + 1)/2;
    };
 
    auto pref_sum = [&](sll x) {
        if (x == 0) return (sll)(0);
        sll ans = 0;
        for (sll d = 1; d <= (sll)sqrt((ll)x); d++){
            // check d^2 + 1 to x
            ans += d; // d^2
 
            sll top = floor(x * 1.0/d);
            sll bot = d; // don't count m where d > sqrt(m)
            ans += max((sll)(0), top - bot) * d; // count d < sqrt(m)
            ans += cons_sum(bot, top); // count m/d
        }
 
        return ans;
    };
 
    print(pref_sum(b) - pref_sum(a - 1));
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}