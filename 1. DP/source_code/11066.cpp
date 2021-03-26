#include <bits/stdc++.h>

using namespace std;

const int MX = 505;

long long int sum[MX], arr[MX];
long long int cache[MX][MX];

long long int f(int a, int b){
    if(a == b) return 0;
    if(cache[a][b]) return cache[a][b];
    long long int ret = 98765432187654321;
    for(int k = a; k < b; k++) ret = min(ret, f(a, k) + f(k + 1, b) + sum[b] - sum[a - 1]);
    return cache[a][b] = ret;
}

int T, K;

int main(){
    cin >> T;
    while(T--){
        cin >> K;
        for(int i = 1; i <= K; i++) cin >> arr[i], sum[i] = sum[i - 1] + arr[i];
        for(int i = 1; i <= K; i++)
        for(int j = 1; j <= K; j++) cache[i][j] = 0;
        cout << f(1, K);
    }
}