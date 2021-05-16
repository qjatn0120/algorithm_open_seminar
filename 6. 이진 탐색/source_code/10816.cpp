#include <bits/stdc++.h>

using namespace std;

int N, arr[100005], M, x;

int main(){
    cin.tie(nullptr), ios::sync_with_stdio(false);
    cin >> N;
    for(int i = 0; i < N; i++) cin >> arr[i];
    sort(arr, arr + N);
    cin >> M;
    while(M--){
        cin >> x;
        cout << (upper_bound(arr, arr + N, x) - lower_bound(arr, arr + N, x)) << " ";

    }

}