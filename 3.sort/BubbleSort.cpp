#include <iostream>
using namespace std;

int n, arr[1010];
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	// 버블 정렬은 큰 수부터 뒤에서 정렬됨!!
	int temp;
	for (int i = 0; i < n; i++) {
		//for (int j = i; j < n-i; j++)
		for (int j = 0; j < (n - i)-1; j++) { // 0부터 시작해서 (n-i)-1까지..*
			if (arr[j] > arr[j+1]) {
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		cout << arr[i]<<'\n';
	}
	return 0;
}
