/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-06-09
 * Contest: 1984 - Codeforces Global Round 26
 * Problem: D
 **/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

void solve()
{
    string s;
    cin >> s;

    string curr = "";

    vector<string> block;
    vector<int> a_block;

    int count = 0;
    int a_count = 0;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'a')
        {
            a_count++;
            count++;
            if (curr != "")
            {
                block.pb(curr);
            }
            curr = "";
        }
        else
        {
            if (a_count != 0)
            {
                a_block.pb(a_count);
            }
            a_count = 0;
            curr += s[i];
        }
    }

    if (curr != "")
    {
        block.pb(curr);
    }

    if (a_count != 0)
    {
        a_block.pb(a_count);
    }

    bool a_start = (s[0] == 'a');
    int s_count = (a_start ? a_block[0] : 0);
    bool a_end = (s[s.size() - 1] == 'a');
    int e_count = (a_end ? a_block[a_block.size() - 1] : 0);

    ll ans = 0;

    if (block.size() == 0){
        cout << count - 1 << endl;
        return;
    }

    for (int i = 0; i <= count; i++)
    {
        bool first = true;
        if ((block.size() % (i + 1)) != 0)
        {
            first = false;
        }
        else
        {
            for (int j = 0; j < block.size() - (i + 1); j++)
            {
                if (block[j] != block[j + i + 1])
                {
                    first = false;
                    break;
                }
            }
        }

        if (first)
        {
            int mn = INT_MAX;
            for (int j = (a_start ? 1 : 0) + i + 1; j < a_block.size() - (a_end ? 1 : 0); j += i + 1)
            {
                mn = min(mn, a_block[j]);
            }

            ans++;
            for (int p = 0; p <= s_count; p++)
            {
                ans += min(mn - p, e_count) + 1;
            }
        }

        if (i == 0)
        {
            continue;
        }

        bool second = true;
        if ((block.size() % i) != 1 || block.size() == i + 1)
        {
            second = false;
        }
        else
        {
            string k = block[0];
            string crit = block[i + 1];
            if (crit.substr(crit.size() - k.size()) != k)
            {
                second = false;
                break;
            }
            for (int j = 1; j < block.size() - i; j++)
            {
                if (block[j] != block[j + i])
                {
                    second = false;
                    break;
                }
            }
        }

        if (second)
        {
            ans++;
        }
    }

    cout << ans << endl;
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