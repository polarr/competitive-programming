#include <bits/stdc++.h>

using namespace std;

int main(){
    int l;
    cin >> l;
    vector <int> k;
    for (int i = 0; i < l; ++i){
        int x;
        cin >> x;
        k.push_back (x);
    }

    unsigned long long ans = 0;
    for (int i = 1; i < k.size(); i++){
        if (k[i] < k[i - 1]){
            ans += k[i - 1] - k[i];
            k[i] = k[i - 1]; 
        }
    }

    cout << ans;
    return 0;
}