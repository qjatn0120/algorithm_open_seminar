#include <bits/stdc++.h>

using namespace std;

const int MX = 1e6 + 5;

int N;
bool prime[MX];

int main(){
    cin >> N;
    memset(prime, -1, sizeof(prime));
    prime[0] = prime[1] = false;
    for(int i = 2; i <= N; i++){
        if(prime[i]){
            for(int j = i * 2; j <= N; j += i) prime[j] = false;
        }
    }
    if(N < 8){
        cout << -1;
        return 0;
    }
    if(N % 2) cout << "2 3 ", N -= 5;
    else cout << "2 2 ", N -= 4;
    for(int i = 2; i < N; i++){
        if(prime[i] && prime[N - i]){
            cout << i << " " << (N - i);
            return 0;
        }
    }
}
