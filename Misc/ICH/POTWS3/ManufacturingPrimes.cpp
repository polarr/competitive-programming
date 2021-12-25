/** Code by 1egend **/
#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;

bool checkPrime(long long x){
    if (x == 1){
        return false;
    }
    for (int i = 2; i <= floor(sqrtf(x)); ++i){  
        if (x % i == 0){
            return false;
        }
    }
    return true;
}

void solve(){
    string x;
    cin >> x;
    bool left = true;
    bool right = true;
    string r;
    for (int i = 0; i < x.length(); ++i){
        if (x[i] == '0'){
            cout << "none";
            return;
        }
    }
    for (int i = 0; i < x.length(); ++i){
        r += x[i];
        if (!checkPrime(stoll(r))){
            right = false;
            break;
        }
    }
    
    string l;
    for (int i = x.length() - 1; i >= 0; --i){
        l.insert(0,1, x[i]);
        if (!checkPrime(stoll(l))){
            left = false;
            break;
        }
    }
    if (left && right){
        cout << "both";
    }
    else if (right){
        cout << "right";
    }
    else if (left){
        cout << "left";
    }
    else{
        cout << "none";
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    // cout << "Case #" << t  << ": " << endl;
    solve();
    return 0;
}