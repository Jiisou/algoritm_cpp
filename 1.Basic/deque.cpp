#include <iostream>
#include <deque> // 덱 헤더파일
using namespace std;
int main() { // 덱의 8가지 명령 처리하기
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); // 백만번까지 입력이 있을 수 있으므로 미리미리 fast I/O를 위한 라인 추가
	int n;
	cin >> n;
	deque<int> dq; // 정수를 저장하는 Deque 선언

	for (int i = 0; i < n; i++) {
		int op; // 명령이 숫자로 주어진다.
		cin >> op;
		if (op == 1) { //명령1: 정수 X를 덱의 앞에 넣는다.
			int x;
			cin >> x;
			dq.push_front(x);
		} else if (op == 2) { //정수 X를 덱의 뒤에 넣는다.
			int x;
			cin >> x;
			dq.push_back(x);
		}
		else if (op == 3) { //덱에 정수가 있다면 맨 앞의 정수를 빼고 출력
			if (dq.empty())
				cout << -1 << '\n';
			else {
				cout << dq.front() << '\n';
				dq.pop_front();
			}
		}
		else if (op == 4) { //덱에 정수가 있다면 맨 뒤의 정수를 빼고 출력
			if (dq.empty())
				cout << -1 << '\n';
			else {
				cout << dq.back() << '\n';
				dq.pop_back();
			}
		}
		else if (op == 5) { //덱의 크기(정수 개수)를 출력
			cout << dq.size() << '\n';
		}
		else if (op == 6) { //덱이 비어있는지(1) 아닌지(0) 출력
			if (dq.empty())
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}
		else if (op == 7) { //덱에 정수가 있다면 맨 앞의 정수를 출력
			if (dq.empty())
				cout << -1 << '\n';
			else
				cout << dq.front() << '\n';
		}
		else //op == 8: 덱에 정수가 있다면 맨 뒤의 정수를 출력
		{ 
			if (dq.empty())
				cout << -1 << '\n';
			else 
				cout << dq.back() << '\n';
		}

	}
	return 0;
}
