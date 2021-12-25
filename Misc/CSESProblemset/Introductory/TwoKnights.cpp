#include <bits/stdc++.h>

using namespace std;

int main(){
    int x;
    cin >> x;

    for (unsigned long long i = 1; i <=x ; ++i){
        cout << i * i * (i * i - 1)/2 - (i-2) * (i-1) * 4 << endl;
    }
    return 0;
}