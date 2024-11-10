/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-11-06
 * Contest: CSES Problemset - Additional Problems
 * Problem: 1670
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

void solve(){
    // I wonder if there is faster sol with some symmetric group theory

    string st = "";
    for (int i = 0; i < 9; i++){
        string s; cin >> s;
        st += s;
    }

    vector<pair<int, int>> swap = {
        {0, 1}, {1, 2}, {3, 4}, {4, 5}, {6, 7}, {7, 8},
        {0, 3}, {1, 4}, {2, 5}, {3, 6}, {4, 7}, {5, 8}
    };


    unordered_map<string, int> dist;

    queue<string> q;
    q.push("123456789");
    dist["123456789"] = 1;

    while(!q.empty()){
        string n = q.front();
        q.pop();

        for (int j = 0; j < 12; j++){
            pair<int, int> sw = swap[j];
            string node = n;
            node[sw.first] = n[sw.second];
            node[sw.second] = n[sw.first];

            if (dist[node] != 0){
                continue;
            }

            dist[node] = dist[n] + 1;
            q.push(node);
        }
    }

    cout << dist[st] - 1 << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}