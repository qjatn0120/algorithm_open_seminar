#include <bits/stdc++.h>

using namespace std;

int T, N;
long long int DP[105];

/*
	초기항
	DP[1] = DP[2] = DP[3] = 1
	DP[4] = DP[5] = 2

	점화식
	DP[i] = DP[i-1] + DP[i-5]
*/

int main(){
	// n = 1, 2, ... 100 에 대해 미리 DP[n]을 계산
    DP[1] = DP[2] = DP[3] = 1;
    DP[4] = DP[5] = 2;
    for(int i = 6; i <= 100; i++) DP[i] = DP[i - 5] + DP[i - 1];

    cin >> T;
    while(T--){
        cin >> N;
        cout << DP[N] << "\n"; // 계산해 두었던 DP[n]을 출력
    }
}
