#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int x;
        cin >> x;
        vector <int> a;
        vector <int> b;
        int mina = 1000000000;
        for (int i = 0; i < x; i++){
            int z;
            cin >> z;
            a.push_back(z);
            mina = min<int> (mina, z);
        }
        int minb = 1000000000;
        for (int i = 0; i < x; i++){
            int z;
            cin >> z;
            b.push_back(z);
            minb = min<int> (minb, z);
        }

        long long ans = 0;
        for (int i = 0; i < x; i++){
            ans += max<int> (a[i] - mina, b[i] - minb);
        }

        cout << ans << endl;
    }
    return 0;
}