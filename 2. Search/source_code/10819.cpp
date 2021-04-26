#include <bits/stdc++.h>

using namespace std;

int N, A[10], ans;
vector <int> v;

int main(){
    cin.tie(nullptr), ios::sync_with_stdio(false);
    cin >> N;
    for(int i = 0; i < N; i++) cin >> A[i];
    sort(A, A + N); // 처음 순열로 만듦
    do{
        int sum = 0;
        for(int i = 1; i < N; i++) sum += abs(A[i - 1] - A[i]); // 주어진 식 계산
        ans = max(ans, sum); // ans를 최댓값으로 갱신
    }while(next_permutation(A, A + N)); // 마지막 순열까지 반복
    cout << ans;
}
