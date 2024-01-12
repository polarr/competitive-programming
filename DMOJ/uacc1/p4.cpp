/**
 * Solution by 1egend (polarity.sh)
 * Date: 2023-01-08
 * Contest: DMOJ UACC 1
 * Problem: P4 - Converging Streams
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

unordered_map<int, vector<pair<int, double>>> flowdowns;
unordered_map<int, pair<double, double>> confirmed;
unordered_map<int, int> pollution;

void visit(int i){
    if (confirmed.count(i) == 1){
        return;
    }

    double pollutionTotal = 0;
    double volume = 0;
    for (pair<int, double> edge : flowdowns[i]){
        int vertex = edge.first;
        if (confirmed.count(vertex) == 0){
            visit(vertex);
        }

        double vol = confirmed[vertex].second * edge.second;

        pollutionTotal += confirmed[vertex].first * vol;
        volume += vol;
    }

    confirmed[i] = make_pair(pollutionTotal / volume + (double) pollution[i], volume);
}

void solve(){
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int u, v, f;
        cin >> u >> v >> f;
        flowdowns[v].pb(make_pair(u, (double) f * 1.0 / 100));
    }
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        pollution[i + 1] = x;
        if (flowdowns[i].size() == 0){
            // initial node
            confirmed[i] = make_pair(pollution[i], 1);
        }
    }
    for (int i = 1; i < n + 1; i++){
        visit(i);
        cout << std::setprecision(10) << std::fixed << confirmed[i].first << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}