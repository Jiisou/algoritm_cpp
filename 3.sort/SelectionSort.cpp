#include <iostream>
using namespace std;
// 가장 작은 원소를 찾아서 제일 앞의 위치로 옮기자! "선택 정렬"; 앞에서부터 정렬됨.
// O(N^2)

int n, arr[1010];
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int temp, min, index;
	for (int i = 0; i < n; i++) {
		min = 9999; //충분히 큰 수로 min을 초기화
		for (int j = i; j < n; j++) { //각 순회
			if (arr[j] < min) { 
				min = arr[j];
				index = j;
			}
		}
		temp = arr[i];
		arr[i] = min;
		arr[index] = temp;
	} // 1번 순회 > 가장 작은 값 > 제일 처음 위치 원소와 스와핑!
	
  for (int i = 0; i < n; i++) {
		cout << arr[i] << '\n';
	}
	return 0;
}
