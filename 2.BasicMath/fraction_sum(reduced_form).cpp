// boj.kr/1735 : 분수합
#include<iostream>
#include<stack>
using namespace std;

// find greatest common divisor 
int gcd(int a, int b) {
	while (b != 0) { //유클리드 호제법 구현 이용(반복문 사용한 방법)
		int temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}
int main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;

	int x, y, g;
	x = a * d + c * b;
	y = b * d;
	g = gcd(x, y);

	cout << x / g << ' '<< y / g << '\n';

	return 0;
}
