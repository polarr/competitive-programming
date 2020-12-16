/** Code by 1egend **/
#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;

ull choose(int n, int k){
    if (k > n) return 0;
    if (k * 2 > n) k = n-k;
    if (k == 0) return 1;

    ull result = n;
    for( int i = 2; i <= k; ++i ) {
        result *= (n-i+1);
        result /= i;
    }
    return result;
}
int main(){
    string s;
    cin >> s;
    int x = 0;
    for (int i = 0; i < s.length(); ++i){
        if (s[i] == '0'){
            x ++;
        }
    }
    cout << fixed << choose(x, 2);
    return 0;
}
