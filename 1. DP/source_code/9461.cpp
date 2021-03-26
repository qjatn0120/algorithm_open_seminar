#include <bits/stdc++.h>

using namespace std;

int T, N;
long long int DP[105];

int main(){
    DP[1] = DP[2] = DP[3] = 1;
    DP[4] = DP[5] = 2;
    for(int i = 6; i <= 100; i++) DP[i] = DP[i - 5] + DP[i - 1];
    cin >> T;
    while(T--){
        cin >> N;
        cout << DP[N] << "\n";
    }
}
