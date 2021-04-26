#include <bits/stdc++.h>

using namespace std;

const int dir_x[4] = {0, 1, 0, -1};
const int dir_y[4] = {1, 0, -1, 0};

int N, arr[30][30];
vector <int> ans;

int DFS(int x, int y){ // x, y에서 DFS를 실행하고, 방문한 지점의 개수를 반환
    int ret = 1; // 현재 지점을 포함한 방문한 지점의 개수
    arr[y][x] = 0; // 방문 체크
    for(int dir = 0; dir < 4; dir++){ // 네 방향에 대해 계산
        int px = x + dir_x[dir], py = y + dir_y[dir]; // 다음 지점 계산
        if(arr[py][px]) ret += DFS(px, py); // 만약 다음 지점이 아직 체크하지 않은 지점이면 DFS 진행
    }
    return ret;
}

int main(){
    cin.tie(nullptr), ios::sync_with_stdio(false);

    // 입력
    cin >> N;

    for(int j = 1; j <= N; j++){
        string str;
        cin >> str; // 띄어쓰기 구분 없이 한 줄로 입력이 들어오기 때문에 한 줄씩 처리
        for(int i = 1; i <= N; i++){
            arr[j][i] = str[i - 1] - '0';
        }
    }

    // 계산
    for(int j = 1; j <= N; j++)
    for(int i = 1; i <= N; i++){
        if(arr[j][i]) ans.push_back(DFS(i, j)); // 만약 집을 발견했다면, 해당 집을 포함하는 단지의 크기를 계산하고 그 결과를 ans에 추가
    }

    // 출력
    sort(ans.begin(), ans.end()); // 정렬
    cout << ans.size() << "\n"; // 정답 개수 출력
    for(int i : ans) cout << i << "\n"; // 정답 출력
}
