// 2470 : 두 용액
#include <iostream>
#include <algorithm>
#include <climits> // INT_MAX 상수 사용하기 위함 or <limits.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int n, a[100001], ans[2]; // 출력 정답배열 추가로 필요
	cin >> n; // 2 이상 100,000 이하
	for (int i = 0; i <n; i++) {
		cin >> a[i];	// -1,000,000,000 이상 1,000,000,000 이하
	}
	sort(a, a + n);

	int left = 0;
	int right = n-1; // 반대 방향
	int min = INT_MAX;
	while (left < right) {
		int sum = a[left] + a[right];
		if (abs(sum) < min) {
			min = abs(sum);
			ans[0] = a[left];
			ans[1] = a[right];
      if (sum ==0) break; // 없으면 시간 초과
		}

		if (sum > 0) {
			right--;
		}
		else if (sum < 0) {
			left++;
		}
		
	}
	cout << ans[0] << ' ' << ans[1] << '\n';
	return 0;
}
