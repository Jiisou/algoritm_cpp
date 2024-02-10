// 2003 : 수들의 합 2
#include <iostream>
using namespace std;

int main() {
	int n, m, a[100001];
	cin >> n>> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int cnt=0;
	for (int i = 0; i < n; i++) {
		int sum = 0; //added
		for (int j = i; j < n; j++) { // start from i
			sum += a[j];
			if (sum == m) {
				cnt++;
				// sum -= a[i]; 처음(i=0)부터 구간 늘리며 부합하는지 확인하고 초기화한 다음 두번째 위치부터(i=1) 또 끝까지.. 하므로 
				break;  // i++; 이전 위치나 값을 따로 처리해주지 않아도 됨.
			}
		}
	}
	
	cout << cnt;
	return 0;
}
