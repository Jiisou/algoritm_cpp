// boj.kr/9012 : vps
#include<iostream>
#include<stack>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		string str; 
		cin >> str;

		string ans = "YES";
		stack<char> p;
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == '(') {
				p.push(str[i]);
			}
			else if (!p.empty()&& str[i] == ')' && p.top()=='(') { // 대응하는 '('가 있는지도 같이 확인해주어야 함!!
				p.pop();
			}
			else {
				ans = "NO";
				break; //vps 아님이 판정났으므로 종료
			}
		}
		if (!p.empty()) ans = "NO";

		cout << ans<<'\n';
	}
	return 0;
}
