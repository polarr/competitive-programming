/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-05-30
 * Contest: Codeforces 1976 - Educational Codeforces Round 166 (Rated for Div. 2)
 * Problem: A
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
    int n;
    string password;
    cin >> n >> password;

    bool isLetter = false;
    int curr = 0;
    for (int i = 0; i < n; i++)
    {
        char x = password[i];
        if (isLetter && isdigit(x))
        {
            cout << "NO" << endl;
            return;
        }

        if (!isLetter && !isdigit(x))
        {
            isLetter = true;
            curr = (x - 'a');
            continue;
        }

        if (!isLetter && isdigit(x))
        {
            int val = (x - '0');
            if (val < curr)
            {
                cout << "NO" << endl;
                return;
            }
            else
            {
                curr = val;
            }

            continue;
        }

        int val = (x - 'a');
        if (val < curr)
        {
            cout << "NO" << endl;
            return;
        }
        else
        {
            curr = val;
        }
    }

    cout << "YES" << endl;
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