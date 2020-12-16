#include <bits/stdc++.h>

using namespace std;

int fulldisplace(string x, char m){
    int ans = 0;
    for (int i = 0; i < x.length(); i++){
        if (x[i] != m){
            ++ans;
        }
    }
    return ans;
}
int displace(string x, char m){
    if (x.length() == 1){
        return (x[0] == m ? 0:1);
    }

    return min<int>(displace(x.substr(0, x.length()/2), static_cast<char>(m + 1)) + fulldisplace(x.substr(x.length()/2, x.length()/2), m), fulldisplace(x.substr(0, x.length()/2), m) + displace(x.substr(x.length()/2, x.length()/2), static_cast<char>(m + 1)));
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int x;
        string a;
        cin >> x >> a;
        cout << displace(a, 'a') << endl;
    }
    return 0;
}