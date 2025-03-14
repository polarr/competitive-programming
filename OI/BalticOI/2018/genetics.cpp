/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-03-13
 * Contest: Baltic OI 2018
 * Problem: genetics
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

mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<ll> distrib(1, INT_MAX);

vector<char> dna = {'A', 'C', 'G', 'T'};

void solve(){
    ll n, m, k; cin >> n >> m >> k;

    vl w(n);
    ll total = 0;
    rep(i, 0, n){
        w[i] = distrib(rng);
        total += w[i];
    }

    vector<vl> ww(m, vl(4, 0));

    vector<string> words(n);

    rep(i, 0, n){
        string s; cin >> s;
        words[i] = s;
        rep(j, 0, m){
            rep(k, 0, 4){
                ww[j][k] += (s[j] == dna[k]) * w[i];
            }
        }
    }

    rep(i, 0, n){
        ll check = 0;
        rep(j, 0, m){
            rep(k, 0, 4){
                if (dna[k] != words[i][j]) check += ww[j][k];
            }
        }

        if (check == (total - w[i]) * k){
            cout << i + 1 << endl;
            return;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}