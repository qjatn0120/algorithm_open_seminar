#include <bits/stdc++.h>

using namespace std;

const int MX = 1005; // 1000(N의 최댓값) + 5(안전을 위한 추가 공간)

int N, A[MX], cache[MX];

/*
    F(n) = n번째 원소를 마지막 원소로 하는 부분 수열 중
           길이가 최대인 부분 증가 수열의 길이

    마지막 원소가 i번째 원소인 부분 수열에서 n번째 원소를 맨 끝에 추가한다.
    F(n) = max{F(i)} + 1 for i < n and A[i] < A[n]
    F(1) = 1
*/

int F(int n){
    // 기저 상황
    if(n == 1) return 1;

    // 메모이제이션
    if(cache[n]) return cache[n];

    // 계산
    int ret = 0;
    for(int i = 1; i < n; i++){
        if(A[i] < A[n]) ret = max(ret, F(i));
    }
    ret++;

    // 저장 및 반환
    cache[n] = ret;
    return ret;
}

int main(){
    cin.tie(nullptr), ios::sync_with_stdio(false); // 입출력 가속
    cin >> N; // 배열 길이 입력
    for(int i = 1; i <= N; i++) cin >> A[i]; // 배열 입력
    int ans = 0;
    for(int i = 1; i <= N; i++) ans = max(ans, F(i)); // 정답 계산
    cout << ans; // 정답 출력
}
