/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-03-12
 * Contest: Codeforces ICPC Practice 595585
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
    int n, m; cin >> n >> m;

    vector<vi> adj(n);
    map<pii, bool> beats;

    vector<vi> votes;

    auto gen = [&](int i, int j){
        vi a = {i, j};
        rep(k, 0, n){
            if (k != i && k != j){
                a.pb(k);
            }
        }
        votes.pb(a);
        reverse(all(a));
        swap(a[a.size() - 1], a[a.size() - 2]);
        votes.pb(a);
    };

    rep(i, 0, m){
        int a, b; cin >> a >> b;
        --a; --b;
        gen(a, b);
    }

    cout << "YES" << endl;
    cout << votes.size() << endl;
    rep(i, 0, votes.size()){
        cout << votes[i][0] + 1;
        rep(j, 1, n){
            cout << " " << votes[i][j] + 1;
        }

        cout << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}