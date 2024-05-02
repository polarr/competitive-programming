/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-04-28
 * Contest: DMOJ Spring Coding Bowl 2024
 * Problem: 1
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

void solve(){
    int n; cin >> n;
    vector<int> obj(3, 0);
    for (int i = 0; i < n; i++){
        string x;
        cin >> x;
        if (x == "rock"){
            obj[0]++;
        } else if (x == "paper"){
            obj[1]++;
        } else {
            obj[2]++;
        }
    }

    if (obj[0] == obj[1] && obj[0] == obj[2]){
        cout << "no" << endl;
        return;
    }

    cout << "yes";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}