/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-10-04
 * Contest: USACO 2016 Jan Gold
 * Problem: 1
**/

#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

const string iofilename = "angry";
ifstream fin(iofilename + ".in");
ofstream fout(iofilename + ".out");

// Use fstream (fin, fout) instead of iostream!
void solve(){
    int n; fin >> n;

    vector<int> prune(n);
    vector<int> hay;
    for (int i = 0; i < n; i++){
        int x; fin >> x;
        prune[i] = x;
    }

    sort(prune.begin(), prune.end());

    hay.pb(prune[0]);

    for (int i = 1; i < n; i++){
        if (prune[i] != prune[i - 1]){
            hay.pb(prune[i]);
        }
    }
    
    n = hay.size();

    vector<int> diff(n, 0);
    for (int i = 1; i < n; i++){
        diff[i] = hay[i] - hay[i - 1];
    }

    vector<int> left(n, 0);
    vector<int> right(n, 0);

    int curr = 0;
    for (int i = n - 1; i >= 0; i--){
        curr = max(curr, diff[i + 1] - i);
        right[i] = curr + i;
    }

    curr = 0;
    for (int i = 0; i < n - 1; i++){
        curr = max(curr, diff[i] + i);
        left[i] = curr - i;
    }

    double ans = 10e9;

    for (int i = 0; i < n; i++){
        double c = (double) max(left[i], right[i]);
        ans = min(ans, c);
    }

    for (int i = 0; i < n - 1; i++){
        double c = ((double) diff[i + 1])/2;
        c = max(c, 1 + (double) max(left[i], right[i + 1]));
        ans = min(ans, c);
    }

    fout << fixed << setprecision(1) << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    solve();
    return 0;
}