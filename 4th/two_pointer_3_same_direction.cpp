// 1806 : 부분합 
// "연속된 수들의 부분합이 S 이상이 되는 것 중, 가장 짧은 것의 길이"

#include <iostream>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int n, a[100001], s; //(10 ≤ N < 100,000) (0 < S ≤ 100,000,000)

	cin >> n >> s;
	for (int i = 0; i <n; i++) { //start from 1*
		cin >> a[i]; // 1000 이하 자연수
	}
	
	int len = 100000001; //* INT_MAX 비주얼스튜디오에선 돌아가는데 백준에선 컴파일 에러(미정의, 헤더파일이 따로 있나?)
	int left = 0;
	int right = 0; // 같은 방향
	int sum = a[left];
	while (right < n) {
		if (sum < s) {
			right++;
			sum += a[right];
		}
		else if (sum >= s) {
			len = min(len, right - left + 1);
			sum -= a[left];
			left++;
		}
	}
	
	if (len == 100000001) cout << 0;
	else	cout << len;
	return 0;
}
