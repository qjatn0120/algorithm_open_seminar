#include <bits/stdc++.h>

using namespace std;

stack <int> st;
string str;
int n, tmp;

int main(){
    cin.tie(nullptr), ios::sync_with_stdio(false); // cin, cout 가속
    cin >> n; // n 입력
    while(n--){
        cin >> str; // 명령 입력
        if(!str.compare("push")){ // push 명령이라면
            cin >> tmp; // push할 숫자 입력
            st.push(tmp); // push 진행
        }else if(!str.compare("pop")){ // pop 명령이라면
            if(st.empty()){
                cout << "-1\n"; // stack이 비었다면 -1 출력
            }else{
                cout << st.top() << "\n"; // stack의 가장 위에 있는 숫자를 출력하고,
                st.pop(); // 그 숫자를 stack에서 삭제
            }
        }else if(!str.compare("size")){ // size 명령이라면
            cout << st.size() << "\n"; // size를 출력
        }else if(!str.compare("empty")){ // empty 명령이라면
            cout << st.empty() << "\n"; // empty 여부 출력
        }else if(!str.compare("top")){ // top 명령이라면
            if(st.empty()){
                cout << "-1\n"; // stack이 비었다면 -1 출력
            }else{
                cout << st.top() << "\n";
            }
        }
    }
}
