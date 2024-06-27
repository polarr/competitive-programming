/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-06-27
 * Contest: 1989 - Educational Codeforces Round 167 (Rated for Div. 2)
 * Problem: E
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAXN = 2e5 + 1;
const ll MOD = 998244353;

/** Combinatorics Library */

ll fac[MAXN + 1];
ll inv[MAXN + 1];

ll exp(ll x, ll n, ll m)
{
    x %= m;
    ll res = 1;

    while (n > 0)
    {
        if (n % 2 == 1)
        {
            res = res * x % m;
        }

        x = x * x % m;
        n /= 2;
    }

    return res;
}

void factorial(ll p)
{
    fac[0] = 1;

    for (int i = 1; i <= MAXN; i++)
    {
        fac[i] = fac[i - 1] * i % p;
    }
}

void inverses(ll p)
{
    inv[MAXN] = exp(fac[MAXN], p - 2, p);

    for (int i = MAXN; i >= 1; i--)
    {
        inv[i - 1] = inv[i] * i % p;
    }
}

ll choose(ll n, ll r, ll p)
{
    return fac[n] * inv[r] % p * inv[n - r] % p;
}

void solve()
{
    int n, k;
    cin >> n >> k;

    factorial(MOD);
    inverses(MOD);

    ll ans = 0;
    for (int i = 1; i < k + 1; i++)
    {
        ans += (choose(n - 1, i - 1, MOD) * choose(k, i, MOD) % MOD);
        ans %= MOD;
    }

    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}