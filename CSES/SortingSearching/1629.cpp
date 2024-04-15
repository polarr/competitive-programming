/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-04-13
 * Contest: CSES Problemset
 * Problem: 1629. Sorting and Searching - Movie Festival
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

    vector<pair<int, int>> movies;
    for (int i = 0; i < n; i++){
        int a, b; cin >> a >> b;

        movies.pb(make_pair(b, a));
    }

    sort(movies.begin(), movies.end());

    int ans = 0;
    int time = 0;

    for (int i = 0; i < n; i++){
        pair<int, int> movie = movies[i];

        if (movie.second >= time){
            ans++;
            time = movie.first;
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