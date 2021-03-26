#include <bits/stdc++.h>

using namespace std;

int N, ans, tmp, DP[10005][3], arr[10005];

int main(){
    cin >> N;
    for(int i = 1; i <= N; i++) cin >> arr[i];
    for(int i = 1; i <= N; i++){
        DP[i][0] = max(DP[i - 1][0], max(DP[i - 1][1], DP[i - 1][2]));
        DP[i][1] = DP[i - 1][0] + arr[i];
        DP[i][2] = DP[i - 1][1] + arr[i];
    }
    cout << max(DP[N][0], max(DP[N][1], DP[N][2]));
}
