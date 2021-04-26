#include <bits/stdc++.h>

using namespace std;

const int MX = 1005;
const int dir_x[4] = {0, 1, 0, -1};
const int dir_y[4] = {1, 0, -1, 0};

int M, N, arr[MX][MX];

int main(){
    cin.tie(nullptr), ios::sync_with_stdio(false);
    cin >> M >> N;  // 배열 크기 입력
    // memset을 이용하여 arr을 모두 -1로 초기화한다.
    // 0또는 -1로 초기화하는 경우에만 사용할 수 있다.
    // 만약 2, 10, 123 등 0이나 -1이 아닌 값으로 초기화하려면
    // fill 함수를 사용할 수 있다.
    memset(arr, -1, sizeof(arr));
    for(int j = 1; j <= N; j++)
    for(int i = 1; i <= M; i++) cin >> arr[j][i]; // 배열 입력

    // BFS
    queue <pair<int, int> > q;
    for(int j = 1; j <= N; j++)
    for(int i = 1; i <= M; i++){
        if(arr[j][i] == 1) q.push({i, j}); // 익은 토마토는 q에 추가
    }

    while(!q.empty()){
        // q 맨 앞의 원소 가져오기
        pair <int, int> pos = q.front();
        q.pop();
        int x = pos.first, y = pos.second;

        for(int dir = 0; dir < 4; dir++){ // 상하좌우 네 방향에 대해 탐색
            // next 위치의 x, y 좌표 계산
            int px = x + dir_x[dir], py = y + dir_y[dir];
            if(arr[py][px]) continue; // -1로 빈칸 또는 방문한 적이 있는 칸이면 건너뜀
            arr[py][px] = arr[y][x] + 1;
            q.push({px, py});
        }
    }

    // BFS 종료

    bool chk = false; // 익지 않은 토마토가 있는 지 여부
    int ans = 0; // 익는 데 걸리는 최대 시간

    for(int j = 1; j <= N; j++)
    for(int i = 1; i <= M; i++){
        if(!arr[j][i]) chk = true;
        ans = max(ans, arr[j][i]);
    }

    if(chk) cout << -1;
    else cout << ans - 1;
}
