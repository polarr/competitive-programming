/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-06-05
 * Contest: CCO 2025 Day 1
 * Problem: 3
**/

#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
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

const ll MAX_N = 46;
const ll MOD = 1e9 + 7;

bool check(ll x, ll b){
    for (ll i = 3; i <= b; i++){
        ll cnt = 0;
        ll sum = 0;

        ll xx = x;

        while (xx > 0){
            sum += xx % i;
            cnt++;
            xx /= i;
        }

        if (sum * 2 != (i - 1) * cnt){
            return false;
        }
    }

    return true;
}

vl pow2(MAX_N, 1);

ll generate(ll n, ll b, int len, int left, ll num){
    if (left == 0){
        if (num < n || !check(num, b)) return LLONG_MAX;
        return num;
    }

    if (len == left){
        num += pow2[left] - 1;
        if (num < n || !check(num, b)) return LLONG_MAX;
        return num;
    }

    ll lo = generate(n, b, len - 1, left, num);

    if (lo != LLONG_MAX){
        return lo;
    }

    return generate(n, b, len - 1, left - 1, num + pow2[len - 1]);
}

void solve(){
    ll b = 4, n = 10e10;

    ll lg = log2(n) + 1;
    if (lg % 2 == 1){
        lg++;
    }

    for (int i = lg; i < MAX_N; i += 2){
        ll gen = generate(n, b, i - 1, i/2 - 1, pow2[i - 1]);
        if (gen != LLONG_MAX){
            cout << gen << endl;
            return;
        }
    }

    cout << -1 << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    rep(i, 1, MAX_N){
        pow2[i] = pow2[i - 1] * 2;
    }

    solve();
    return 0;
}