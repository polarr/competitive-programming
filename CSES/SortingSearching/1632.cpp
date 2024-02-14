/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-02-11
 * Contest: CSES Problemset - Sorting and Searching
 * Problem: 1632 - Movie Festival II
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

void solve(){
    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> movies;

    for (int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        movies.pb(make_pair(b, a));
    }

    sort(movies.begin(), movies.end());
    int ans = 0;
    multiset<int> members;
    for (int i = 0; i < k; i++){
        members.insert(-1);
    }

    for (int i = 0; i < n; i++){
        pair<int, int> movie = movies[i];

        if (members.upper_bound(movie.second) == members.begin()){
            continue;
        }

        ans++;
        int val = *prev(members.upper_bound(movie.second));
        members.erase(members.find(val));
        members.insert(movie.first);
    }

    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}