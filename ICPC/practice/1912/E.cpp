/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-10-12
 * Contest: ICPC Practice Codeforces 1912
 * Problem: E
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

void solve(){
    // bruh ll not big enough?
    ll p, q; cin >> p >> q;
    cout << fixed << setprecision(0);

    string ans = "0";

    if ((abs((ll)p) % 2) != (abs((ll)q) % 2)){
        // odd
        ans += "+12-11";
        p -= 1;
        q += 10;
    }

    // even
    ll avg = p/2.0 + q/2.0;
    ll diff = abs(avg - p);

    //cout << p << endl << q << endl << avg << endl;

    bool isneg = avg < 0;
    string opr = (isneg ? "-":"+");

    bool more = (p >= avg);

    avg = abs(avg);

    int c = 0;
    while(avg != 0){
        int m = avg % 10;
        string mm = to_string(m);
        if (m != 0){
            ans += ("+0" + opr + mm + opr);
            for(int i = 0; i < c; i++){
                ans += "9";
            }
            if (c == 0){
                ans += "0";
            }
            ans += ("*" + mm + opr + "0");
        }
        c++;
        avg /= 10;
    }

    c = 0;
    while(diff != 0){
        int m = diff % 10;
        string mm = to_string(m);
        if (m != 0){
            ans += "+";
            if (more){
                ans += mm;
                for (int i = 0; i < c - 1; i++){
                    ans += "0";
                }
                if (c > 0){
                    ans += mm;
                }
                ans += "-";
                if (c == 0){
                    ans += "0";
                } else {
                    ans += mm;
                }
            } else {
                if (c == 0){
                    ans += "0";
                } else {
                    ans += mm;
                }
                ans += "-";
                ans += mm;
                for (int i = 0; i < c - 1; i++){
                    ans += "0";
                }
                if (c > 0){
                    ans += mm;
                }
            }
        }

        c++;
        diff /= 10;
    }

    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}