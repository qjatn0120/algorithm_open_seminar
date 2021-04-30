#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b){
    return b == 0 ? a : gcd(b, a % b);
}

int x, y;

int main(){
    cin >> x >> y;
    cout << gcd(x, y) << "\n" << (x * y / gcd(x, y));
}
