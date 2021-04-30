#include <bits/stdc++.h>

using namespace std;

int M, N;
bool prime[1000005];

int main(){
    cin >> M >> N;
    memset(prime, -1, sizeof(prime));
    prime[0] = prime[1] = false;
    for(int i = 2; i <= N; i++){
        if(prime[i]){
            for(int j = i * 2; j <= N; j += i) prime[j] = false;
        }
    }
    for(int i = M; i <= N; i++){
        if(prime[i]) cout << i << "\n";
    }
}
