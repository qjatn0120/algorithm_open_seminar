#include <bits/stdc++.h>

using namespace std;

long long int A, N;

struct INFO{
    long long int g, x, y;
    INFO(long long int g, long long int x, long long int y) : g(g), x(x), y(y) {}
};

INFO gcd(long long int a, long long int b){
    pair <long long int, long long int> r = {max(a, b), min(a, b)}, s = {1, 0}, t = {0, 1};

    while(r.second){
        long long int q = r.first / r.second;
        r.first -= r.second * q;
        s.first -= s.second * q;
        t.first -= t.second * q;
        swap(r.first, r.second);
        swap(s.first, s.second);
        swap(t.first, t.second);
    }

    return INFO(r.first, s.first, t.first);
}

int main(){
    cin >> N >> A;
    INFO ans = gcd(N, A);
    cout << (N - A) << " ";
    if(ans.g != 1) cout << -1;
    else cout << ((ans.y % N) + N) % N;
}
