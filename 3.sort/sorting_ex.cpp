#include <iostream>
using namespace std;
// 수 정렬하기 #2750

int n, arr[1010];
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int temp;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) { 
			if (arr[i] > arr[j]) {
				temp = arr[j];
				arr[j] = arr[i];
				arr[i] = temp;
			} // 1번 순회 > 가장 작은 값 > 제일 처음 위치 원소와 스와핑 (!=선택정렬)
		}
	} // O(N^2)
	for (int i = 0; i < n; i++) {
		cout << arr[i]<<'\n';
	}
	return 0;
}
