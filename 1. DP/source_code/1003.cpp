#include <bits/stdc++.h>

using namespace std;

const int MX = 45; // N의 최댓값 40 + 안전을 위한 여유 공간 5
int T, N;

pair <int, int> cache[MX]; // 메모이제이션을 위한 공간
/*
    pair <int, int> 는
    struct{
        int first;
        int second;
    };
    와 동일하다고 생각하시면 됩니다.
*/

// F(n) : fibonacci(n)이 0과 1을 출력하는 횟수
pair <int, int> F(int n){
    // 기저 상황(초기 상황)
    if(n == 0) return {1, 0};
    if(n == 1) return {0, 1};
    // 메모이제이션
    // n이 2 이상이면 무조건 0이 하나 이상은 출력되므로,
    // cache[n].first가 1 이상이면 값이 이미 계산되어 있다고 할 수 있습니다.
    if(cache[n].first) return cache[n];

    // 계산
    pair <int, int> ret1, ret2;
    ret1 = F(n - 1);
    ret2 = F(n - 2);
    pair <int, int> ret = {ret1.first + ret2.first, ret1.second + ret2.second};

    // 저장 및 반환
    cache[n] = ret;
    return ret;
}

int main(){
    cin.tie(nullptr), ios::sync_with_stdio(false); // 입출력 가속
    cin >> T; // 테스트케이스의 수 입력
    while(T--){ // 테스트케이스의 수 만큼 수행
        cin >> N; // N 입력
        pair <int, int> ans = F(N); // 정답 계산
        cout << ans.first << " " << ans.second << "\n"; // 정답 출력
    }
}
