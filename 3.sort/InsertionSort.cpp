#include <iostream>
using namespace std;
// 1 ≤ N ≤ 1,000

int n, arr[1010];
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int i, j, key;
	for (i = 0; i < n; i++) {
		key = arr[i]; // :삽입될 위치를 결정해야 하는 원소
    for (j = i - 1; j >= 0; j--) { // key 값 바로 앞에서 부터 하나씩 비교
	    if (arr[j] > key) { //key 값보다 큰 값이 존재하면
		    arr[j + 1] = arr[j]; //그 값을 한 칸 뒤로 이동
	    } else break; // key보다 작은 값이 나오면 비교 및 이동 중단 ! 왜냐면 그 앞으로는 계속 key보다 작을거니까.. 왜냐면 비교가 진행되는 구간은 정렬된 상태니까!!
    }
		arr[j + 1] = key; // 찾은 위치에 key값 '삽입' **j+1 ;**key보다 '작은 값이 발견된 위치'에서부터 한 칸 뒤니까!!!!
	}

	for (int i = 0; i < n; i++) {
		cout << arr[i] << ' ';
	}
	return 0;
}
