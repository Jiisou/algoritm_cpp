// 3273 : 두 수의 합
#include <iostream>
#include <algorithm> // 라이브러리 내에 정의된 sort 함수 사용하기 위함
using namespace std;

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int n, a[100001], x;
	cin >> n;
	for (int i = 0; i < n; i++) { 
		cin >> a[i];
	}
	cin >> x;

	sort(a, a+n); // c++ STL sort문법 <시작위치, 끝위치>
	
	int left = 0;
	int right = n -1; // index
	int cnt = 0;
	while (left < right) {
		int sum = a[left] + a[right];
		if (sum == x) {
			cnt++;
			left++;
		}
		else if (sum < x) {
			left++;
		}
		else { // sum >x
			right--;
		}
	}
	cout << cnt;
	return 0;
}
