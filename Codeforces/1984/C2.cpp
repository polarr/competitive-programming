/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-06-09
 * Contest: 1984 - Codeforces Global Round 26
 * Problem: C2
 **/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 998244353;

void solve()
{
    int n;
    cin >> n;

    vector<ll> arr;
    for (int i = 0; i < n; i++)
    {
        ll a;
        cin >> a;
        arr.pb(a);
    }

    ll mx = 0;
    ll mn = 0;

    vector<ll> mx_arr(n + 1, 0), mn_arr(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        mx = max(abs(mx + arr[i]), abs(mn + arr[i]));
        mx_arr[i + 1] = mx;
        mn = mn + arr[i];
        mn_arr[i + 1] = mn;
    }

    ll maximum = mx;

    ll ans = 0;
    ll mult = 1;

    vector<ll> cs(n + 2);
    ll c = 1;
    for (int j = 1; j < n + 1; j++)
    {
        if (mn_arr[j] >= 0)
        {
            c *= 2;
            c %= MOD;
        }

        cs[j + 1] = c;
    }

    for (int i = n - 1; i >= 0; i--)
    {   
        if (maximum == abs(mn_arr[i] + arr[i]))
        {
            ll c = cs[i + 2];
            c *= mult;
            c %= MOD;

            ans += c;
            ans %= MOD;
        }

        if (mx_arr[i] == mn_arr[i]){
            break;
        }

        if (maximum == abs(mx_arr[i] + arr[i]))
        {
            if (mx_arr[i] + arr[i] >= 0)
            {
                mult *= 2;
                mult %= MOD;
            }
            maximum = mx_arr[i];
        } else {
            break;
        }
    }

    cout << ans % MOD << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc;
    cin >> tc;
    for (int t = 1; t <= tc; ++t)
    {
        // cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}