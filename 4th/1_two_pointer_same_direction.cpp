// 2003 : 수들의 합 2
#include <iostream>
using namespace std;

int main() {
	int n, m, a[100001];
	cin >> n>> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int left=0;
	int right=0;
	int sum = a[0];
	int cnt = 0;
	//for (int i = 0; i < n; i++) (Xx)
	while(right <n)	{
		if (sum < m) {
			right++;
			sum += a[right]; // ++right
		}
		else if (sum > m) {
			sum -= a[left]; // left++
			left++;
		}
		else { //sum == x
			cnt++;
			//sum -= a[left]; 있어도 되고
			//left++;         없어도 되네?
			right++;
			sum += a[right];
		}
	}
	cout << cnt;
	return 0;
}
