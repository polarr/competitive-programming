/** Code by 1egend **/
#include <bits/stdc++.h>

using namespace std;

int main(){
    int x;
    cin >> x;
    vector <int> n;
    for (int i = 0; i < x; ++i){
        int k;
        cin >> k;
        n.push_back(k);
    }
    sort(n.begin(), n.end());
    int ans = ceil(x/2.0) - 1;
    vector <int> a(n);
    for (int i = 0; i < ans; i++){
        a[2 * i + 1] = n[i];
    }
    for (int i = ans; i < x - 1; i++){
        int z = 2 * (i - ans);
        a[z] = n[i];
    }
    cout << ans << endl;
    a[a.size() - 1] = n[n.size() - 1];
    for (int i = 0; i < a.size(); i ++){
        cout << a[i] << " ";
    }
    return 0;
}
