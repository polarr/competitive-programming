/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-10-16
 * Contest: ICPC Practice Codeforces 558894
 * Problem: I
 **/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 998244353;

ll mod_exp(ll x, ll n, ll m)
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

template <class T>
class BIT
{

private:
    int size;
    vector<T> bit;
    vector<T> arr;

public:
    BIT(int size) : size(size), bit(size + 1), arr(size) {}

    /** Sets the value at index ind to val. */

    void set(int ind, T val) { add(ind, val - arr[ind]); }

    /** Adds val to the element at index ind. */

    void add(int ind, T val)
    {

        arr[ind] += val;

        ind++;

        for (; ind <= size; ind += ind & -ind)
        {
            bit[ind] += val;
        }
    }

    /** @return The sum of all values in [0, ind]. */

    T pref_sum(int ind)
    {

        ind++;

        T total = 0;

        for (; ind > 0; ind -= ind & -ind)
        {
            total += bit[ind];
            total %= MOD;
        }

        return total;
    }
};

void solve()    
{
    int n, m;
    cin >> n >> m;
    vector<ll> fact(max(n, m), 1);
    for (int i = 1; i < max(n, m); i++)
    {
        fact[i] = fact[i - 1] * i;
        fact[i] %= MOD;
    }

    vector<int> s(n);
    vector<int> t(m);

    map<int, int> cnt;

    ll denom = 1;
    ll total = 0;

    BIT<ll> counts(2e5 + 1);

    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
        counts.add(s[i], 1);
        cnt[s[i]]++;
        total++;
        denom *= cnt[s[i]];
        denom %= MOD;
    }

    for (int i = 0; i < m; i++)
    {
        cin >> t[i];
    }

    denom = mod_exp(denom, MOD - 2, MOD);

    ll ans = 0;
    ll remain = n;
    for (int i = 0; i < m; i++)
    {
        if (remain == 0)
        {
            ans++;
            break;
        }

        ll ad = denom;

        ad *= fact[remain - 1];
        ad %= MOD;
        ad *= counts.pref_sum(t[i] - 1);
        ad %= MOD;

        ans += ad;
        ans %= MOD;

        if (cnt[t[i]] == 0)
        {
            break;
        }

        counts.add(t[i], -1);
        denom *= cnt[t[i]];
        denom %= MOD;

        cnt[t[i]]--;
        remain--;
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