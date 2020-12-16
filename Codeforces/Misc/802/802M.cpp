#include <bits/stdc++.h>

using namespace std;

int main(){
    int a, b;
    cin >> a >> b;
    vector <int> x;
    while (a--){
        int z;
        cin >> z;
        x.push_back(z);
    }

    sort(x.begin(), x.end());
    int ans = 0;

    for (int i = 0; i < b; ++i){
        ans += x[i];
    }
    cout << ans;
    return 0;
}