/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-01-29
 * Contest: USACO 2024 Jan Contest
 * Problem: Silver P1. Cowmpetency
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

void solve(){
    int n, q, c;
    cin >> n >> q >> c;

    int pre = 0;
    vector<int> sequence(n + 1);
    vector<int> prefix(n + 1);
    set<int> forgotten = { 0 };

    for (int i = 1; i < n + 1; i++){
        int x;
        cin >> x;
        if (x == 0){
            forgotten.insert(i);
            x = 1;
        }
        pre = max(pre, x);
        sequence[i] = x;
        prefix[i] = pre;
    }

    vector<pair<int, int>> memory;
    for (int i = 0; i < q; i++){
        int a, h;
        cin >> a >> h;
        memory.pb(make_pair(a, h));
    }

    sort(memory.begin(), memory.end());

    int mx = 0;
    for (int i = 0; i < q; i++){
        pair<int, int> mem = memory[i];

        if (i > 0 && mem.second == memory[i - 1].second){
            continue;
        }

        if (i > 0 && mem.first < memory[i - 1].second){
            cout << -1 << endl;
            return;
        }

        if (max(mx, prefix[mem.first]) != max(mx, prefix[mem.second - 1])){
            int forget = *(--forgotten.upper_bound(mem.first));
            if (forget == 0 || (i > 0 && forget < memory[i - 1].second)){
                cout << -1 << endl;
                return;
            }
            mx = prefix[mem.second - 1];
            sequence[forget] = mx;
            if (mx > c){
                cout << -1 << endl;
                return;
            }
        }

        if (forgotten.count(mem.second) > 0){
            mx = max(mx, prefix[mem.second - 1]) + 1;
            sequence[mem.second] = mx;
            if (mx > c){
                cout << -1 << endl;
                return;
            }
        } else if (sequence[mem.second] <= max(mx, prefix[mem.second - 1])){
            cout << -1 << endl;
            return;
        }
    }


    /*
    for (int i = 0; i < forgotten.size(); i++){
        int forget = forgotten[i];

        int possibleMin = 1;
        int possibleMax = c;
        for (int m = 0; m < q; m++){
            pair<int, int> mem = memory[m];
            
            if (forget < mem.second && sequence[mem.second] != 0){
                possibleMax = min(possibleMax, sequence[mem.second] - 1);
            }
            
            if (forget <= mem.first){
                if (prefix[mem.second - 1] > prefix[mem.first] && (i == forgotten.size() - 1 || forgotten[i + 1] > mem.first)){
                    possibleMin = max(possibleMin, prefix[mem.second - 1]);
                }
            }

            if (forget == mem.second){
                possibleMin = max(possibleMin, prefix[mem.second - 1] + 1);
            }
        }

        if (possibleMin > possibleMax){
            cout << -1 << endl;
            return;
        }

        sequence[forget] = possibleMin;
        for (int j = forget; j < n + 1; j++){
            prefix[j] = max(prefix[j], possibleMin);
        }
    }
    */

    for (int i = 1; i < n + 1; i++){
        cout << sequence[i];
        if (i < n){
            cout << " ";
        }
    }

    cout << endl;
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