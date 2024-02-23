#include<iostream>
using namespace std;
int main() {
    cin.tie(NULL); ios::sync_with_stdio(false);
	int t, n, m, a,b; 
	cin >> t;
	while (t--) {
		cin >> n >> m; // n is vertex, and m is edge
        for(int i =0;i<m;i++) cin >> a>> b;
		cout << n - 1 << '\n';
		// input is a fake...
        //The number of edges in a tree is equal to the number of vertices minus 1.
	}

	return 0;
}
