/**
 * Solution by 1egend (polarity.sh)
 * Date: 2025-02-13
 * Contest: POI
 * Problem: mafia
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
    vi target = vi(n);
    vi degree = vi(n, 0);
    vector<bool> dead = vector<bool>(n, false);

    rep(i, 0, n){
        int x;
        cin >> x;
        --x;
        target[i] = x;
        degree[x]++;
    }

    int mn = 0, mx = n;
    
    // max 
    rep(i, 0, n){
        if (dead[i]){
            continue;
        }

        int ii = i;
        int s = ii;
        bool cycle = true;

        while(!dead[ii]){
            dead[ii] = true;
            if (degree[ii] != 1){
                cycle = false;
            }
            ii = target[ii];
        }

        if (cycle && ii == s && target[i] != i){
            mx--;
        }
    }

    dead = vector<bool>(n, false);

    // min
    queue<int> q;
    rep(i, 0, n){
        if (degree[i] == 0){
            mx--;
            q.push(i);
            dead[i] = true;
        }
    }

    while (!q.empty()){
        int x = q.front();
        q.pop();
        int t = target[x];
        if (dead[t]){
            continue;
        }

        dead[t] = true;
        mn++;

        int tt = target[t];
        degree[tt]--;
        if (degree[tt] == 0){
            q.push(tt);
            dead[tt] = true;
        }
    }

    // cout << mn << endl;

    rep(i, 0, n){
        if (dead[i]){
            continue;
        }
        int ii = i;
        int s = ii;
        int l = 1;
        while(target[ii] != s){
            dead[ii] = true;
            l++;
            ii = target[ii];
        }

        dead[ii] = true;

        mn += l - l/2;
    }

    cout << mn << " " << mx << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}