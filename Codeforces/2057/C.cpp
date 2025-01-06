/**
 * Solution by 1egend (polarity.sh)
 * Date: 2025-01-04
 * Contest: 
 * Problem: C
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

void solve(){
    int l, r; cin >> l >> r;

    int top = pow(2, 30) - 1;
    int bot = 0;

    int lo = l;
    int hi = r;

    vector<ll> binl(30, 0);
    int j = 0;
    j = 0;
    while (lo > 0){
        binl[j] = (lo % 2); 
        lo /= 2;
        j++;
    }

    vector<ll> binh(30, 0);
    j = 0;
    while (hi > 0){
        binh[j] = (hi % 2); 
        hi /= 2;
        j++;
    }

    auto check = [&](int x){
        vector<ll> binx(30, 0);
        int j = 0;
        while (x > 0){
            binx[j] = (x % 2); 
            x /= 2;
            j++;
        }

        for (int i = 29; i >= 0; i--){
            if (binx[i] == 1){
                if ((binh[i] == binl[i])){
                    return false;
                }

                return true;
            } else {
                if (binh[i] != binl[i]){
                    return true;
                }
            }
        }

        return true;
    };

    while (bot < top){
        int mid = (bot + top + 1)/2;

        bool can = check(mid);
        // cout << mid << " " << can << endl;

        if (can){
            bot = mid;
        } else {
            top = mid - 1;
        }
    }

    // cout << bot << endl;

    vector<ll> binx(30, 0);
    int x = bot;
    j = 0;
    while (x > 0){
        binx[j] = (x % 2); 
        x /= 2;
        j++;
    }

    vector<ll> bina(30, 0);
    vector<ll> binb(30, 0);
    vector<ll> binc(30, 0);

    int count = 0;

    j = 0;
    int jj;
    for (int i = 0; i < 30; i++){
        if (binx[i] == 1){
            if (j == 0){
                jj = i;
            } 
            else if (!(binh[i] == 0 && binl[i] == 1)){
                if (binl[i] == 1){
                    bina[i] = 1;
                    binb[i] = 0;
                    binc[i] = 1;
                    bina[jj] = 1;
                    binb[jj] = 1;
                    binc[jj] = 0;
                    continue;
                }
                bina[i] = 0;
                binb[i] = 1;
                binc[i] = 0;
                bina[jj] = 1;
                binb[jj] = 0;
                binc[jj] = 0;
            } else {
                bina[i] = 0;
                binb[i] = 1;
                binc[i] = 1;
            }
        } else {
            bina[i] = binh[i];
            binb[i] = binh[i];
            binc[i] = binh[i];
        }

        j++;
    }

    int a = 0, b = 0, c = 0;
    for (int i = 0; i < 30; i++){
        int d = pow(2, i);
        a += bina[i] * d;
        b += binb[i] * d;
        c += binc[i] * d;
    }


    cout << to_string((a ^ b) + (b ^ c) + (c ^ a)) << endl;
    cout << a << " " << b << " " << c << endl;
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