// 15552번 - Stack2
#include <iostream>
#include <stack> // 스택 사용하기 위해 반드시 포함해야 하는 헤더파일
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); // 백만번까지 입력이 있을 수 있으므로 미리미리 fast I/O를 위한 라인 추가
	
	int n;
	cin >> n;
	stack<int> stk; // 컨테이너 템플릿을 이용해 스택 생성
	for (int i = 0; i < n; i++) {
		int op;
		cin >> op;
		if (op == 1)
		{ //명령 1 = 원소 삽입 = push(X)
			int x;
			cin >> x;
			stk.push(x);
		} else if (op == 2)
		{ //명령 2 = 원소 존재 확인, 빼고 출력
			if (stk.empty())
				cout << -1 <<'\n';
			else {
				cout << stk.top() << '\n';
				stk.pop(); // pop()은 최상단 요소를 삭제하지만 반환하진X
			}
		}
		else if (op == 3) { //명령 3 = 원소 개수 =  size() 
			cout<< stk.size() <<'\n';
		}
		else if (op == 4) { //명령 4 = 비었는지 여부 = empty() : 1/0
			if (stk.empty())
				cout << 1;
			else
				cout << 0;
		}else //op == 5 
		{ 
			//명령 5 = 맨 뒤 요소 출력 
			if (stk.empty())
				cout << -1 << '\n';
			else 
				cout<<stk.top()<<'\n';
		}

	}
	return 0;
}
