// boj.kr/14490 : 백대열
#include <iostream>
using namespace std;

int gcd(int a, int b) { //최대공약수 (=유클리드 호제법)
	while (b != 0) {
		int temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}
int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio;
	string input;
	cin >> input;
	int n, m;
	for (int i = 0; i < input.size(); i++) {
		if (input[i] == ':') {
			string n1 = input.substr(0,i); // i는 포함되지 않으므로
			//+씨쁠쁠에선 string[0:i] 각괄호범위x substr(0,i)메소드를!
			string m1 = input.substr(i + 1, input.length());
      // size() vs length(); 두 메서드는 언제나 같은 값을 반환하지만, 전자는 객체가 메모리에서 실제 사용하고 있는 크기를, 후자는 문자열의 단순 길이를 의미함.

			n = stoi(n1); // STring tO Int method
			m = stoi(m1);
		}
	}
	//cout << n << ':' << m << '\n';

	int g = gcd(n, m);
	cout << n/g << ':' << m/g << '\n';

}
