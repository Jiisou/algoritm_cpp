#include <iostream>
using namespace std;
// 1 ≤ N ≤ 1,000,000

int n, arr[1001001], sorted[1001001]; // 전역 변수로 선언함으로써 함수간 호출시 발생할 수 있는 불필요한 메모리 문제 해소 가능.

// 두 개의 정렬된 부분 배열을 이용해 새롭게 정렬된  배열을 만들어내는 함수
void merge(int A[], int start, int middle, int end) {
	int i = start;
	int j = middle + 1;
	int k = start;

	// 순서대로 배열에 삽입
	while (i <= middle && j <= end) { // 작은 부분집합내에서 이동하며 두 집합을 비교해 채워 넣음.
		if (A[i] <= A[j]) {
			sorted[k] = A[i];
			i++; //정렬 집합에 넣고 나서는 현 부분집합에서 다음 위치로 이동.
		}
		else {
			sorted[k] = A[j];
			j++;
		} // 더 작은 값부터 채워넣음.
		k++; //뭐라도 들어왔으면 다음 칸으로 이동.
	}

	// 두 부분집합 중 먼저 끝까지 도달한 경우 나머지 집합의 데이터를 채워넣어야 함.
	// 남은 데이터 삽입
	if (i > middle) { // i의 부분집합이 먼저 끝남
		for (int t = j; t <= end; t++) {
			sorted[k] = A[t];
			k++;
		}
	}
	else {
		for (int t = i; t <= middle; t++) {
			sorted[k] = A[t];
			k++;
		}
	}
	//정렬된 배열을 삽입
	for (int t = start; t <= end; t++) {
		// 모든 위치를 방문하면서 정렬된 배열의 값을 실제 배열로 이동시켜줌
		A[t] = sorted[t];
	}

}void mergeSort(int a[], int start, int end) {
	//if (start >= end) return;
	if (start < end) {
		int middle = (start + end) / 2;  //홀수면 1개 차이로 나뉠 것, 중요X
		mergeSort(a, start, middle);
		mergeSort(a, middle + 1, end);

		merge(a, start, middle, end); // 병합정렬 수행하고 나중에 합침 =합병
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	mergeSort(arr, 0, n - 1); // end 인자는 인덱스 값이므로 크기 n에 -1 해야 함!

	for (int i = 0; i < n; i++) {
		cout << arr[i] << '\n';
	}
	return 0;
}
