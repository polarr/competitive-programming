#include <bits/stdc++.h>

using namespace std;

// Collatz Conjecture
int main(){
    unsigned long long x;
    cin >> x;
    cout << x << " ";
    while (x != 1){
        if (x % 2 == 0){
            x/= 2;
        }
        else{
            x *= 3;
            x++;
        }
        cout << x << " ";
    }
    return 0;
}