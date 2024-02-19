/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-01-31
 * Contest: CSES Problemset - Additional Problems
 * Problem: 1188 - Bit Inversions
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

// NOT SOLVED, correct idea too lazy to finish implementation
void solve(){
    string b;
    cin >> b;
    int n = b.length();
    set<int> runs = { 0, 1 };
    multiset<int> mx;
    int start = 1;
    for (int i = 2; i < n + 1; i++){
        if (b[i - 1] != b[i - 2]){
            runs.insert(i);
            mx.insert(i - start);
            start = i;
        }
    }

    mx.insert(n + 1 - start);
    runs.insert(n + 1);

    int m;
    cin >> m;
    for (int i = 0; i < m; i++){
        int x;
        cin >> x;

        int c = *(--runs.upper_bound(x));
        int p = *(--(--runs.upper_bound(x)));
        int nx = *(runs.upper_bound(x));
        int nnx = *(++runs.upper_bound(x));

        if (c < x && x < nx - 1){
            runs.insert(x);
            runs.insert(x + 1);
            mx.erase(mx.find(nx - c));
            mx.insert(x - c);
            mx.insert(1);
            mx.insert(nx - x - 1);
            //cout << *(--mx.end()) << " ";
            continue;
        }

        if (x > 1 && x < n && c == x && x == nx - 1){
            runs.erase(x);
            mx.erase(mx.find(nx - c));
            mx.erase(mx.find(c - p));
            mx.erase(mx.find(nnx - nx));
            mx.insert(nnx - p);
            //cout << *(--mx.end()) << " ";
            continue;
        }

        if (x > 1 && c == x){
            runs.erase(x);
            runs.insert(x + 1);
            mx.erase(mx.find(nx - c));
            mx.erase(mx.find(c - p));
            mx.insert(nx - c - 1);
            mx.insert(c - p + 1);
        }

        if (x < n && x == nx - 1){
            runs.erase(x + 1);
            runs.insert(x);
            mx.erase(mx.find(nx - c));
            mx.erase(mx.find(nnx - nx));
            mx.insert(nx - c - 1);
            mx.insert(nnx - nx + 1);
        }

        // cout << *(--mx.end()) << " ";
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}	