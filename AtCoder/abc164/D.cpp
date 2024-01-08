/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-01-07
 * Contest: AtCoder Beginner Contest 164
 * Problem: D
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

vector <int> modPs;

void solve(){
    string x;
    cin >> x;
    int s = x.size();
    unordered_map <int, int> count;
    count[0] = 1;
    int curr = 0;
    ull ans = 0;
    for (int i = 0; i < s; i++){
        curr = (curr * 10 + (x[i] - '0')) % 2019;
        count[modPs[i % 1344] * curr % 2019]++;
    }

    for (auto element : count){
        ans += element.second * (element.second - 1) / 2;
    }

    cout << ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int prod = 1;

    for (int i = 0; i < 1344; i++){
        modPs.pb(prod);
        prod = (prod * 202) % 2019;
    }

    solve();
    return 0;
}