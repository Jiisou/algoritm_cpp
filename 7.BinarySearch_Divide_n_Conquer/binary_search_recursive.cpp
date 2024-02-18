// 1920 : 수 찾기
#include <iostream>
#include <algorithm>
using namespace std;

int binary_search(int a[], int target, int start, int end) {
	if (start > end) return 0; // Target not found
	int mid = (start + end) / 2;
	if (a[mid] == target) return 1;
	else if (a[mid] > target) {
		return binary_search(a, target, start, mid - 1);
	}
	else { // (a[mid] < target)
		return binary_search(a, target, mid + 1, end);
	}
} // 재귀 함수로 구현한 이진 탐색

int main() {
	cin.tie(nullptr); ios_base::sync_with_stdio(false);

	int n, arr[101010], m;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n); //added_line ! 이분탐색 적용위해선 배열은 반드시 정렬된 상태여야 함*

	cin >> m;
	for (int i = 0; i <m; i++) {
		int target;
		cin >> target;
		cout << binary_search(arr, target, 0, n - 1) << '\n';
	}
}
// 아래 처럼 두 단계를 분리해 따로 처리시킨 코드는 100ms 가 더 소요됨.
//for (int i = 0; i < m; i++) {
//		cin >> target[i];
//}
//for (int i = 0; i < m; i++) {
//		cout << binary_search(arr, target[i], 0, n - 1)<<'\n';
//}
