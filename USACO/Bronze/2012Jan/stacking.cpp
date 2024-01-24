/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-01-12
 * Contest: USACO 2012 January Contest
 * Problem: Bronze P2. Haybale Stacking
**/

#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;

const string iofilename = "stacking";
ifstream fin(iofilename + ".in");
ofstream fout(iofilename + ".out");

// Use fstream (fin, fout) instead of iostream!
void solve(){
    int n, k;
    cin >> n >> k;

    vector<int> diff(n + 1, 0);
    for (int i = 0; i < k; i++){
        int a, b;
        cin >> a >> b;
        diff[a]++;
        if (b == n){
            continue;
        }
        diff[b + 1]--;
    }

    vector<int> stacks(n, 0);
    int curr = diff[1];
    stacks[0] = curr;
    for (int i = 1; i < n; i++){
        curr += diff[i + 1];
        stacks[i] = curr;
    }

    sort(stacks.begin(), stacks.end());
    
    cout << stacks[(n - 1)/2];

    /** O(nk) solution
    unordered_map<int, int> values;
    vector<int> stacks(n, 0);
    stacks[0] = n;
    int median = 0;
    int same = n;
    int more = 0;
    for (int i = 0; i < k; i++){
        int a, b;
        cin >> a >> b;
        for (int j = a - 1; j < b; j++){
            if (stacks[j] == median){
                more++;
            }
            values[stacks[j]]--;
            stacks[j]++;
            if (values.count(stacks[j]) == 0){
                values[stacks[j]] = 0;
            }
            values[stacks[j]]++;
            if (stacks[j] == median){
                same++;
            }
            if (more == (n + 1)/2){
                median++;
                same = values[median];
                more -= same;
            }
        }
    }
    cout << median;
    */
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    solve();
    return 0;
}