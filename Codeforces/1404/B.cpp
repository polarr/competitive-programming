/** Code by 1egend **/
#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int a, b, x, y, n;
        cin >> a >> b >> x >> y >> n;
        unsigned long long fA = max<int>(a - n, x);
        unsigned long long fB = max<int>(b - (n - (a - fA)), y);
        unsigned long long sB = max<int>(b - n, y);
        unsigned long long sA = max<int>(a - (n - (b - sB)), x);
        cout << min<unsigned long long>(fA * fB, sB * sA) << endl;
        //cout << min<unsigned long long>(max<int>(a - n, x) * max<int>(y, b - (n - max<int>(a - n, x))), max<int>(b - n, y) * max<int>(y, a - (n - max<int>(b - n, y)))) << endl;
    }
    return 0;
}
