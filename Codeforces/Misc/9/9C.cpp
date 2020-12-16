#include <bits/stdc++.h>
#define ll long long;

using namespace std;

int main(){
    int n;
    cin >> n;
    string x = to_string(n);
    int ans = 0;
    for (int i = 0; i < x.length(); ++i){
        if (x[i] - '0' > '1' - '0'){
            ans += pow(2, x.length() - i) - 1;
            break;
        }
        else if (x[i] == '1'){
            ans += pow(2, x.length() - i - 1);
        }
    }
    cout << ans;
}