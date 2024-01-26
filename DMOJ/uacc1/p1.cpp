/**
 * Solution by 1egend (polarity.sh)
 * Date: 2023-01-08
 * Contest: DMOJ UACC 1
 * Problem: P1 - Bench Press Bob
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

void solve(){
    int n;
    cin >> n;
    cout << (((n - 45) % 90 == 0) ? "Let's go Bob!" : "Rip Bob!");
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}