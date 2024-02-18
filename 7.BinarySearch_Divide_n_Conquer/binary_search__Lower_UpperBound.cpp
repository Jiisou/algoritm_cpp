//10816 : 숫자 카드 2 
#include <iostream>
#include <algorithm>
using namespace std;

int lower_bound(int a[], int target, int start, int end) {
	while (start < end) {
		int mid = (start + end) / 2;
		if (a[mid] >= target) end = mid ; // *등호! =>같아질 때까지 not (end = mid - 1)
		else  start = mid + 1; // (a[mid] < target)
	}
	return start;
}
int upper_bound(int a[], int target, int start, int end) {
	while (start < end) {
		int mid = (start + end) / 2;
		if (a[mid] <= target) start = mid+1;
		else end = mid;
	}
	return start; // (*)
}
int count_card(int a[], int target, int start, int end) {
	int lower = lower_bound(a, target, start, end);
	int upper = upper_bound(a, target, start, end);
	return upper - lower;
}

int main() {
	cin.tie(nullptr); ios_base::sync_with_stdio(false);

	int n, arr[500500], m;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n); // Binary search must be performed on 'an array that is sorted.'

	cin >> m;
	for (int i = 0; i < m; i++) { // The query count variable 'm', is different from the number of elements in the array, 'n'.
		int target;
		cin >> target;
		cout << count_card(arr, target, 0, n) << ' ';
	}
}
