/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-02-01
 * Contest: Happy Hackers Programming Challenge 1
 * Problem: P2 - Yuniformity Challenge
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

void solve(){
    int n, q;
    cin >> n >> q;
    vector<int> arr(n + 1, 0);
    vector<int> zeroes(n + 1, 0);
    unordered_map<int, int> pos;
    unordered_map<int, int> negs;
    vector<int> lastPair(n + 1, -1);
    vector<int> lastDiff(n + 1, -1);

    int z = 0;
    int prev = 0;
    for (int i = 1; i < n + 1; i++){
        int a;
        cin >> a;

        if (i > 1 && a != prev){
            lastDiff[i] = i - 1;
        } else {
            lastDiff[i] = lastDiff[i - 1];
        }

        prev = a;

        if (a == 0){
            ++z;
        }

        zeroes[i] = z;

        if (a < 0){
            negs[-a] = i;
            lastPair[i] = lastPair[i - 1];
            if (pos.count(-a) > 0){
                lastPair[i] = max(lastPair[i], pos[-a]);
            }
        }
        if (a > 0){
            pos[a] = i;
            lastPair[i] = lastPair[i - 1];
            if (negs.count(a) > 0){
                lastPair[i] = max(lastPair[i], negs[a]);
            }
        }
    }

    for (int i = 0; i < q; i++){
        int l, r;
        cin >> l >> r;
        if (lastDiff[r] < l || lastPair[r] >= l || zeroes[r] > zeroes[l - 1]){
            cout << "YES" << endl;
            continue;
        }

        cout << "NO" << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}