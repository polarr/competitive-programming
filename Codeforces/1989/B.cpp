/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-06-27
 * Contest: 1989 - Educational Codeforces Round 167 (Rated for Div. 2)
 * Problem: B
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
    string a, b;
    cin >> a >> b;

    int ans = INT_MAX;
    for (int start = 0; start <= b.size(); start++)
    {
        for (int end = 0; end <= b.size() - start; end++)
        {

            bool can = false;
            int curr = start;
            for (int i = 0; i < a.size(); i++)
            {
                if (curr >= b.size() - end)
                {
                    can = true;
                    break;
                }

                if (a[i] == b[curr])
                {
                    curr++;
                }
            }

            if (curr >= b.size() - end)
            {
                can = true;
            }

            if (can)
            {
                ans = min(ans, (int)a.size() + start + end);
            }
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