/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-02-11
 * Contest: USACO 2015 December Contest
 * Problem: Gold P1. High Card Low Card
**/

#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;

const string iofilename = "cardgame";
ifstream fin(iofilename + ".in");
ofstream fout(iofilename + ".out");

// Use fstream (fin, fout) instead of iostream!
void solve(){
    int n;
    fin >> n;

    set<int> bessie;
    for (int i = 1; i <= 2 * n; i++){
        bessie.insert(i);
    }

    vector<int> high;
    vector<int> low;
    for (int i = 0; i < n; i++){
        int a;
        fin >> a;
        if (i < n/2){
            high.pb(a);
        } else {
            low.pb(a);
        }

        bessie.erase(a);
    }

    vector<int> bessHigh;
    for (int i : bessie){
        bessHigh.pb(i);
    }

    reverse(bessHigh.begin(), bessHigh.end());

    sort(high.begin(), high.end(), greater{});
    sort(low.begin(), low.end());

    int ans = 0;
    int nowHigh = 0, nowBess = 0;
    while(nowBess < n && nowHigh < n/2){
        if (bessHigh[nowBess] > high[nowHigh]){
            bessie.erase(bessHigh[nowBess]);
            ans++;
            nowBess++;
            nowHigh++;
            continue;
        }

        nowHigh++;
    }

    vector<int> bessLow;
    for (int i : bessie){
        bessLow.pb(i);
    }
    nowBess = 0;
    int nowLow = 0;
    while(nowBess < bessLow.size() && nowLow < n/2){
        if (bessLow[nowBess] < low[nowLow]){
            ans++;
            nowBess++;
            nowLow++;
            continue;
        }

        nowLow++;
    }
    
    fout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    solve();
    return 0;
}