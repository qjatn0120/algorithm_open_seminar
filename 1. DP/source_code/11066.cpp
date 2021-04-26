#include <bits/stdc++.h>

using namespace std;

const int MX = 505;

long long int sum[MX], arr[MX];
long long int cache[MX][MX];

/*
    DP[a][b] = a번 파일부터 b번 파일까지 합칠 때 필요할 최소 비용

    초기항
    DP[a][a] = 0

    점화식
    DP[a][b] = min(DP[a][k] + DP[k+1][b]) + SUM(a, b) for k = a, a+1, .. b-1

    SUM(a, b)는 C[a] + C[a+1] + ... + C[b]를 의미한다.
    sum[a] = C[1] + C[2] + ... + C[a]라 정의하면
    SUM(a, b) = sum[b] - sum[a-1]로 O(1)안에 계산할 수 있다.
*/

long long int f(int a, int b){
    if(a == b) return 0; // 초기항 처리
    if(cache[a][b]) return cache[a][b]; // 메모이제이션
    long long int ret = 98765432187654321;
    for(int k = a; k < b; k++) ret = min(ret, f(a, k) + f(k + 1, b) + sum[b] - sum[a - 1]); // 점화식 계산
    return cache[a][b] = ret; // 메모이제이션 및 반환
}

int T, K;

int main(){
    cin >> T;
    while(T--){
        cin >> K;
        for(int i = 1; i <= K; i++) cin >> arr[i], sum[i] = sum[i - 1] + arr[i]; // 입력과 동시에 sum 배열 계산
        for(int i = 1; i <= K; i++)
        for(int j = 1; j <= K; j++) cache[i][j] = 0; // cache 초기화
        cout << f(1, K); // 1번 파일부터 K번 파일까지 합치는 데 필요한 최소 비용 출력
    }
}