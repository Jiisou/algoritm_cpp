#include <iostream>
using namespace std;
// 1 ≤ N ≤ 1,000,000

int n, arr[1001001];
void sort(int A[], int start, int end) {
	// 원소가 1개 또는 0개인 경우
	if (start >= end) return; // return; void형 함수의 종료 
	
	int key = start;
	int i = start + 1;
	int j = end;
	int temp;
	// i와 j가 엇갈릴 때까지 반복
	while (i <= j) { 
		// -> 방향으로 key보다 큰 값을 만날 때까지 이동
		while (A[i]<= A[key]) {
			i++;
		}
		// <- 방향으로 key보다 작은 값 만날 때까지 이동
		while (A[j]>=A[key] 
				&& j>start) { //key보다 작은 값 없더라도 start를 지나쳐선 안됨!
			// 엇갈렸을때 작은 값과 pivot(key)을 교체하므로 i 반복은 제한 조건 없어도됨.
			j--;
		}
		// 엇갈렸다면 = 처음부터 찾기 시작한 큰 값의 인덱스가 뒤에서 시작한 작은 값 위치보다 뒤에 있다면 = 작은 값이 큰 값보다 앞에 있다면
		if (i > j) {
			temp = A[key];
			A[key] = A[j];
			A[j] = temp;
		}
		else { //엇갈리지 않았다면 
			temp = A[i];
			A[i] = A[j];
			A[j] = temp;
		}
	}
  // '반복이 종료되었다' = 엇갈려서 pivot이 이동했다 = pivot을 기준으로 앞 뒤(오-왼)으로 부분 배열이 생겼다.
	sort(A, start, j - 1); //재귀적 호출
	sort(A, j + 1, end);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	
	sort(arr, 0, n-1); // end 인자는 인덱스 값이므로 크기 n에 *-1 해주어야 함!

	for (int i = 0; i < n; i++) {
		cout << arr[i] << ' ';
	}
	return 0;
}
