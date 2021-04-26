#include <bits/stdc++.h>

using namespace std;

int N, ans, tmp, DP[10005][3], arr[10005];

/*
	DP[i][m] => 1번 포도주부터 i번 포도주까지 마실지 말지 결정하고, 지금까지 연속 m번 포도주를 마셨을 때
				마실 수 있는 최대 포도주 양 (m = 0인 경우는 i번째 포도주를 마시지 않은 것으로 취급)

	초기 항
	DP[0][m] = 0

	점화식
	DP[i][m] = max(DP[i-1][0], DP[i-1][1], DP[i-1][2]) if m == 0
	           DP[i-1][0] + arr[i]                     if m == 1
	           DP[i-1][1] + arr[i]                     if m == 2
*/

int main(){
    cin >> N;
    for(int i = 1; i <= N; i++) cin >> arr[i];
    for(int i = 1; i <= N; i++){
    	// c++에서는 max(a, b)의 형태만 지원하므로, max(a, b, c) 형태로 사용하기 위해서는
    	// max 함수를 직접 정의하거나 max(a, max(b, c))의 형태로 사용해야 한다.
    	// 또는 max_element 함수를 사용할 수 있다.
        DP[i][0] = max(DP[i - 1][0], max(DP[i - 1][1], DP[i - 1][2]));
        DP[i][1] = DP[i - 1][0] + arr[i];
        DP[i][2] = DP[i - 1][1] + arr[i];
    }
    cout << max(DP[N][0], max(DP[N][1], DP[N][2]));
}
