/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-09-08
 * Contest: DMOJ bts24 - Back to School '24
 * Problem: 6
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

void solve(){
    int n, k, q;
    cin >> n >> k >> q;

    vector<int> parent(n);
    vector<int> tree(n, false);

    // set<int> sorttree;
    vector<pair<int, int>> nearest;

    for (int i = 0; i < k; i++){
        int x; cin >> x;
        tree[--x] = true;
    }

    for (int i = 1; i < n; i++){
        int x; cin >> x;
        parent[i] = --x;
    }

    int lastTree = -1;
    int firstTree = -1;

    for (int i = 0; i < n; i++){
        if (tree[i]){
            if (firstTree < 0){
                firstTree = i;
            }

            lastTree = i;
            nearest[i] = make_pair(0, i);
            continue;
        }


    }

    int lastAns = 0;

    for (int i = 0; i < q; i++){
        int x, y; cin >> x >> y;

        x ^= lastAns;
        y ^= lastAns;

        --x; --y;

        int curr = x;
        bool original = x < y;

        int ans = 0;
        while (true){
            bool direction = x < y;
            if (direction != original){
                ans += abs(y - x);
                break;
            }

            pair<int, int> nt = nearest[curr];
            bool 
        }

        cout << ans << endl;
        lastAns = ans;
    }


}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}