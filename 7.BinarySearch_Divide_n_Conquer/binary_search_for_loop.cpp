// 1920 : 수 찾기
#include <iostream>
#include <algorithm>
using namespace std;

int binary_search(int a[], int target, int start, int end) {
	while (start <= end){
        int mid = (start+end)/2;
        if (a[mid]>target){
            end = mid-1;
        }
        else if (a[mid]<target){
            start = mid+1;
        }
        else{
            return 1;
        }
    }
    return 0; // 'After the loop ended', the target was not found.
}

int main() {
	cin.tie(nullptr); ios_base::sync_with_stdio(false);

	int n, arr[101010], m;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n); //added_line !

	cin >> m; // 존재 여부를 탐색하고자 하는 쿼리의 수는 n과 다를 수 있음! 따라서 반복횟수를 적절히 처리해야 함^^
	for (int i = 0; i <m; i++) {
		int target;
		cin >> target;
		cout << binary_search(arr, target, 0, n - 1) << '\n';
	}
}
