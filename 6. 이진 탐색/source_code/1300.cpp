#include <bits/stdc++.h>

using namespace std;

const int MX = 1e6 + 5;

int N, k;

int main(){
    cin.tie(nullptr), ios::sync_with_stdio(false);
    cin >> N >> k;
    int lo = 1, hi = 1e9;
    while(lo < hi){
        int mid = (lo + hi) / 2;
        long long int cnt = 0;
        for(int i = 1; i <= N; i++) cnt += min(N, mid / i);
        if(cnt < k) lo = mid + 1;
        else hi = mid;
    }
    cout << lo;
}
