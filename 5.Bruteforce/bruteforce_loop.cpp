// 6131 : 완전 제곱수 "a^2 = b^2 + N"
#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int n; // (1 <=n <=1000)
	cin >> n;

	int a, b;
	int cnt = 0;
	for (a = 1; a <= 500; a++) {
		for (b = a; b <= 500; b++) {
			if (a * a + n == b * b) {
				cnt++;
			}
		}
	}
	cout << cnt;
	return 0;

}
