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
		for (int j = 0; j < (n - i)-1; j++) { // 0부터 시작해서 (n-i)-1까지..* : 맨 뒤에서부터 배열내 가장 큰 수가 확정되니까 
		// 매번 처음부터 시작하되 비교 횟수를 순회가 한번 끝날때마다 (i만큼)줄어야 하고 j와 j+1을 비교하므로 j+1이 배열 크기를 초과하지 않도록 1을 추가로 빼줌!! 
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
