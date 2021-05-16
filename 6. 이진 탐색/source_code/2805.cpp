#include <bits/stdc++.h>

using namespace std;

const int MX = 1e6 + 5;

int N, arr[MX], M;

bool check(int x){
    long long int sum = 0;
    for(int i = 0; i < N; i++){
        if(arr[i] > x) sum += (arr[i] - x);
    }
    return sum >= M;
}

int main(){
    cin.tie(nullptr), ios::sync_with_stdio(false);
    cin >> N >> M;
    for(int i = 0; i < N; i++) cin >> arr[i];
    int lo = 0, hi = 1e9;
    while(lo < hi){
        int mid = (lo + hi + 1) / 2;
        if(check(mid)) lo = mid;
        else hi = mid - 1;
    }
    cout << lo;
}
