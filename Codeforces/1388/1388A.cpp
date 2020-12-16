#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t > 0){
        int n;
        cin >> n;
        if (n <= 30){
            cout << "NO" << endl;
        }
        else if (n - 30 == 6 || n - 30 == 10|| n - 30 == 14){
            cout << "YES" << endl;
            cout << "6 " << "10 " << "15 " << to_string(n - 31) << endl;
        }
        else{
            cout << "YES" << endl;
            cout << "6 " << "10 " << "14 " << to_string(n - 30) << endl;
        }
        t--;
    }
    return 0;
}