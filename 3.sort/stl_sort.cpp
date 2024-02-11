// 2751 : 수 정렬하기 2
#include <iostream>
#include <algorithm> // algorithm 헤더파일 인클루드를 통해 sort() 사용 가능
using namespace std;

int main() {
    int n, a[1000001];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n); // <문법> 배열의 (시작 위치, 끝 위치)
    for (int i = 0; i < n; i++) {
        cout << a[i] << '\n';
    }
    return 0;
}
