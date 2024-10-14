/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-10-13
 * Contest: Codeforces 2022
 * Problem: D1
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

void solve(){
    int n; cin >> n;
    for (int i = 1; 2 * i <= n; i++){
        cout << "? " + to_string(2 * i) + " " + to_string(2 * i - 1) << endl;
        cout.flush();

        int a; cin >> a;

        cout << "? " + to_string(2 * i - 1) + " " + to_string(2 * i) << endl;
        cout.flush();

        int b; cin >> b;

        if (a != b){
            // one of these guys is imposter
            int c = 1;
            if (i == 1){
                c = 3;
            }

            cout << "? " + to_string(2 * i) + " " + to_string(c) << endl;
            cout.flush();

            int x; cin >> x;

            cout << "? " + to_string(c) + " " + to_string(2 * i) << endl;
            cout.flush();

            int y; cin >> y;

            if (x != y){
                cout << "! " + to_string(2 * i) << endl;
                cout.flush();
            } else {
                cout << "! " + to_string(2 * i - 1) << endl;
                cout.flush();
            }

            return;
        }
    }

    cout << "? " + to_string(n) + " " + to_string(n - 1) << endl;
    cout.flush();

    int a; cin >> a;

    cout << "? " + to_string(n - 1) + " " + to_string(n) << endl;
    cout.flush();

    int b; cin >> b;

    if (a != b){
        // one of these guys is imposter
        int c = 1;

        cout << "? " + to_string(n) + " " + to_string(c) << endl;
        cout.flush();

        int x; cin >> x;

        cout << "? " + to_string(c) + " " + to_string(n) << endl;
        cout.flush();

        int y; cin >> y;

        if (x != y){
            cout << "! " + to_string(n) << endl;
            cout.flush();
        } else {
            cout << "! " + to_string(n - 1) << endl;
            cout.flush();
        }

        return;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for (int t = 1; t <= tc; ++t){
        // cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}