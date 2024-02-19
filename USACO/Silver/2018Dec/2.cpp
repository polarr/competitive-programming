/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-01-31
 * Contest: USACO 2018 December
 * Problem: Silver P2. Convention II
**/

#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;

const string iofilename = "convention2";
ifstream fin(iofilename + ".in");
ofstream fout(iofilename + ".out");

// Use fstream (fin, fout) instead of iostream!
void solve(){
    int n;
    cin >> n;

    priority_queue<int> waiting;
    vector<tuple<int, int, int>> cows;
    vector<tuple<int, int, int>> sortCows;
    for (int i = 0; i < n; i++){
        int a, t;
        cin >> a >> t;
        cows.pb(make_tuple(a, t, n - i));
        sortCows.pb(make_tuple(a, t, i));
    }

    sort(sortCows.begin(), sortCows.end());
    vector<int> cowWait = {0};

    int ans = 0;

    int time = 0;
    pair<int, int> eating = make_pair(get<0>(cow[0]), get<1>(cow[0]));
    for (int i = 1; i < n; i++){
        int cow = cows[i];
        time = get<0>(cow);
        cowWait.pb(time);
        waiting.push(get<2>(cow));
        if (eating.second < time){
            int nextCow = waiting.top();
            waiting.pop();

        }
    }

    cout << ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    solve();
    return 0;
}