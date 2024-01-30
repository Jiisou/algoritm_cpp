#include <iostream>
#include <queue> // 큐 사용을 위한 헤더파일
using namespace std;
int main() { // 큐 처리를 위한 6가지 명령 구현하기
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); // 이백만번까지 입력이 있을 수 있으므로 미리미리 fast I/O를 위한 라인 추가
	
	int n;
	cin >> n;
	queue<int> qu; // 큐 선언

	for (int i = 0; i < n; i++) {
		string op; // 명령이 문자로 바로 주어진다.
		cin >> op;
		if (op == "push") { 
			int x;
			cin >> x;
			qu.push(x);
		}
		else if (op == "pop") { 
			if (qu.empty())
				cout << -1 << '\n';
			else {
				cout << qu.front() << '\n';
				qu.pop();
			}
		} else if (op == "size") {
			cout << qu.size() << '\n';
		}
		else if (op == "empty") {
			if(qu.empty())
				cout << 1 << '\n';
			else 
				cout << 0 << '\n';
		}
		else if (op == "front") {
			if(qu.empty())
				cout<<-1 << '\n';
			else
				cout << qu.front() << '\n';
		}
		else //op == "back"
		{ 
			if (qu.empty())
				cout<<-1 << '\n';
			else
				cout<<qu.back() << '\n';
		}

	}
	return 0;
}
