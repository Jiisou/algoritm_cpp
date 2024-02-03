// boj.kr/17087 : 숨바꼭질 6 (3 or more greatest common divisors)
#include<iostream>
using namespace std;

int gcd(int a, int b) {
	while (b != 0) { //유클리드 호제법
		int temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}
int main() {
	int n, s, a, result;
	cin >> n >> s;
	result = 0;

	for (int i = 0; i < n; i++) {
		cin >> a;
		int distance = abs(s - a);
		if (result != 0) {
			result = gcd(distance, result);
		}
		else {
			result = distance;
		}
	}
	cout << result<<'\n';

	return 0;
}
