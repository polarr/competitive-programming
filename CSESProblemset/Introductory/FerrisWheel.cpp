#include <bits/stdc++.h>

using namespace std;
int main(){
    int l;
    int w;
    cin >> l >> w;
    vector <int> c;
    for (int i = 0; i < l; ++i){
        int z;
        cin >> z;
        c.push_back(z);
    }
    sort(c.begin(), c.end());
    for (float i = c.size() - 1; i >= 0; --i){
        if (c[i] + c[0] <= w){
            cout << c.size() - i - 1 + (ceil((i + 1)/2));
            return 0;
        }
    }
    return 0;
}