/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-06-20
 * Contest: Codeforces 1779
 * Problem: D
**/

#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using pii = pair<int, int>;
#define pb push_back
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

void solve(){
    int n; cin >> n;

    vi a(n), b(n);
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n) cin >> b[i];

    int m; cin >> m;
    map<int, int> razors;
    rep(i, 0, m){
        int x; cin >> x;
        razors[x]++;
    }

    map<int, set<int>> places;
    vector<bool> visited(n, false);

    rep(i, 0, n){
        if (a[i] == b[i]) {
            visited[i] = true;
        }
        if (a[i] < b[i]){
            cout << "NO" << endl;
            return;
        }

        places[b[i]].insert(i);
    }

    vi nle(n, n);
    stack<pii> s;
    for (int i = n - 1; i >= 0; i--){
        while (!s.empty() && s.top().first <= b[i]){
            s.pop();
            continue;
        }

        if (!s.empty()){
            nle[i] = s.top().second;
        }

        s.push({b[i], i});
    }

    rep(i, 0, n){
        if (visited[i]) continue;

        int j = nle[i];
        int x = b[i];
        if (razors[x] == 0){
            cout << "NO" << endl;
            return;
        }
        razors[x]--;
        while (!places[x].empty()){
            auto k = places[x].begin();
            if (*k >= j) break;
            visited[*k] = true;
            places[x].erase(k);
        }
    }

    cout << "YES" << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for (int t = 1; t <= tc; ++t){
        // cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}