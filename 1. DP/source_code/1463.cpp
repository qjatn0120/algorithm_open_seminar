#include <bits/stdc++.h>

using namespace std;

const int MX = 1e6 + 5;

int cache[MX];
int N;

/*
    F(n) : 정수 N을 1로 만들기 위해 필요한 연산의 최소 횟수
    F(n) = min(F(n - 1), F(n / 2) if n이 2의 배수, F(n / 3) if n이 3의 배수) + 1
    F(1) = 0
*/

int F(int n){
    // 기저 상항
    if(n == 1) return 0;

    // 메모이제이션
    if(cache[n]) return cache[n];

    // 계산
    int ret = F(n - 1) + 1;
    if(n % 2 == 0) ret = min(ret, F(n / 2) + 1);
    if(n % 3 == 0) ret = min(ret, F(n / 3) + 1);

    // 저장 및 반환
    cache[n] = ret;
    return ret;
}

int main(){
    cin.tie(nullptr), ios::sync_with_stdio(false); // 입출력 가속
    cin >> N; // N 입력
    cout << F(N); // 정답 출력
}
