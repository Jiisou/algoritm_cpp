#include <iostream>
#include <vector> // push_back 하려고..
using namespace std;

int main() {
	int n;
	cin >> n;
    
	vector<bool> isPrime(n+1, 1);
	for (int i = 2; i*i <= n; i++) { //에라토스테네스의 체
		if (isPrime[i] == 0) continue;
		for (int j = i+i; j <= n; j+=i) {
			isPrime[j] = 0;
		}
	}
	vector<int> prime; // 연속된 소수 집합
	for (int i = 2; i <= n; i++) {
		if(isPrime[i]) prime.push_back(i); //// 판정결과 소수인 값만 벡터 뒤에 추가
	}
    
	int left = 0, right = 0; // 같은 방향 <= 연속된 구간 합
	int sum = 0;
	int cnt = 0;
	while (1) {
		if (sum > n) {
			sum -= prime[left];
			left++;
		}
		else if(sum<n){
			if (right >= prime.size()) break;
			sum += prime[right];
			right++;
		}
		else {
			cnt++;
			if (right >= prime.size()) break;
			sum += prime[right];
			right++;
		}
	}
	cout << cnt;

	return 0;
}
