/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-01-30
 * Contest: USACO 2016 Open Contest
 * Problem: Silver P2. Diamond Collector
**/

#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;

const string iofilename = "diamond";
ifstream fin(iofilename + ".in");
ofstream fout(iofilename + ".out");

// Use fstream (fin, fout) instead of iostream!
void solve(){
    int n, k;
    fin >> n >> k;

    vector<int> diamonds;
    for (int i = 0; i < n; i++){
        int d;
        fin >> d;
        diamonds.pb(d);
    }

    sort(diamonds.begin(), diamonds.end());
    vector<int> preStart(n + 1, 0);
    vector<int> preEnd(n + 1, 0);

    int start = 0;
    int end = 1;
    preStart[1] = 1;
    while (end < n){
        if (diamonds[end] <= diamonds[start] + k){
            end++;
        } else {
            start++;
        }

        if (start == end){
            end++;
        }

        preStart[end] = max(max(preStart[end], preStart[end - 1]), end - start);
    }

    start = n - 1;
    end = n - 2;
    preEnd[n - 1] = 1;
    while (end >= 0){
        if (diamonds[end] >= diamonds[start] - k){
            end--;
        } else {
            start--;
        }

        if (start == end){
            end--;
        }

        preEnd[end + 1] = max(max(preEnd[end + 1], preEnd[end + 2]), start - end);
    }

    int ans = 0;
    for (int i = 0; i < n + 1; i++){
        ans = max(ans, preStart[i] + preEnd[i]);
    }

    fout << ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    solve();
    return 0;
}