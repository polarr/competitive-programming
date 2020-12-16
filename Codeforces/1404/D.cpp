/** Code by 1egend **/
#include <bits/stdc++.h>

using namespace std;

unsigned long long int ipow(unsigned long long int base, int exp )
{
    unsigned long long int result = 1ULL;
    while( exp )
    {
        if ( exp & 1 )
        {
            result *= (unsigned long long int)base;
        }
        exp >>= 1;
        base *= base;
    }
    return result;
}
unsigned long long sol(unsigned long long n, int s){
    string k = to_string(n);
    int dig = 0;
    int sum = 0;
    for (int i = 0; i < k.length(); i++){
        sum += (k[i] - '0');
        if (sum > s){
            dig = k.length() - i;
            break;
        }
    }
    if (dig == 0){
        return 0;
    }

    int ans = ipow(10, dig + 1) - (n % ipow(10, dig + 1));
    return sol(n + ans, s) == 0 ? ans : sol(n + ans, s);
}
int main(){
    int t;
    cin >> t;
    while(t--){
        unsigned long long n;
        int s;
        cin >> n >> s;
        cout << sol(n, s);
    }
    return 0;
}
