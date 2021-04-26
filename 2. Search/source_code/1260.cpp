#include <bits/stdc++.h>

using namespace std;

const int MX = 1005;

int N, M, V, A, B;
bool visited[MX];
vector <int> adj[MX];

void DFS(int pos){
    visited[pos] = true; // pos를 방문했다고 체크
    cout << pos << " ";
    // for(int i = 0; i < adj[pos].size(); i++){
    //      int next = adj[pos][i];
    // }
    // 를 줄여서 for(int next : adj[pos]) 라 표현할 수 있다.
    for(int next : adj[pos]){ // pos와 연결된 노드 next에 대해
        if(visited[next]) continue; // 만약 next가 이미 방문했던 노드라면 무시한다.
        DFS(next); // next에서 DFS 진행
    }
}

void BFS(int pos){
    queue <int> q; // 방문 예정 목록
    q.push(pos); // 방문 예정 목록에 시작 위치 추가
    visited[pos] = true; // 방문 체크
    while(!q.empty()){ // 방문 예정 목록이 빌 때깨지 진행
        int p = q.front(); // 방문 예정 목록에서 가장 앞에 있는 번호를 가져와 방문을 진행한다.
        cout << p << " ";
        q.pop(); // 가져온 번호 삭제
        for(int next : adj[p]){ // p와 연결된 노드 next에 대해
            if(visited[next]) continue; // 만약 next가 이미 방문했던 노드라면 무시한다.
            q.push(next); // 방문 예정 목록에 next 추가
            visited[next] = true; // 방문 체크
        }
    }
}

int main(){
    cin.tie(nullptr), ios::sync_with_stdio(false);
    cin >> N >> M >> V;
    for(int i = 0; i < M; i++){ // 간선 입력
        cin >> A >> B;
        adj[A].push_back(B); // A -> B 방향 간선 추가
        adj[B].push_back(A); // B -> A 방향 간선 추가
    }
    for(int i = 1; i <= N; i++) sort(adj[i].begin(), adj[i].end()); // 작은 번호부터 방문하기 위해 정렬
    memset(visited, 0, sizeof(visited)); // visited 여부를 false로 초기화
    DFS(V); // DFS 진행
    cout << "\n";
    memset(visited, 0, sizeof(visited)); // visited 여부를 false로 초기화
    BFS(V); // BFS 진행
}
