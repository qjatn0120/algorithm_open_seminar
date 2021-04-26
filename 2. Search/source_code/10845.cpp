#include <bits/stdc++.h>

using namespace std;

int n, tmp;
string str;

queue <int> q;

int main(){
    cin.tie(nullptr), ios::sync_with_stdio(false);
    cin >> n;
    while(n--){
        cin >> str;
        if(str == "push"){ // push 명령이라면
            cin >> tmp; // push할 숫자 입력
            q.push(tmp); // push 진행
        }else if(str == "pop"){ // pop 명령이라면
            if(q.empty()){ // queue가 비었다면
                cout << "-1\n"; // -1 출력
            }else{
                cout << q.front() << "\n"; // 맨 앞에 있는 수를 출력하고
                q.pop(); // 맨 앞에 있는 수 삭제
            }
        }else if(str == "size"){ // size 명령이라면
            cout << q.size() << "\n"; // size 출력
        }else if(str == "empty"){ // empty 명령이라면
            cout << q.empty() << "\n"; // empty 여부 출력
        }else if(str == "front"){ // front 명령이라면
            if(q.empty()){ // 만약 queue가 비었다면
                cout << "-1\n"; // -1 출력
            }else{
                cout << q.front() << "\n"; // 맨 앞의 수 출력
            }
        }else if(str == "back"){ // back 명령이라면
            if(q.empty()){ // 만약 queue가 비었다면
                cout << "-1\n"; // -1 출력
            }else{
                cout << q.back() << "\n"; // 맨 뒤의 수 출력
            }
        }
    }
}
