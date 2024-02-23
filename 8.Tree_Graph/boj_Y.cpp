// 31217 - Y 
#include <iostream>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    long long node, edge, i, cnt[101010];
    cin >> node >> edge;
    for (i = 0; i < edge; i++) // 
    {
        long long u, v;
		cin >> u >> v;
        cnt[u] +=1; 
		cnt[v] +=1;
    }

    long long ans = 0;
    for (i = 1; i <= node; i++) // 1~n
    {
        if (cnt[i] <= 2) continue; // == if(cnt[i] >= 3)
        ans += ( cnt[i] * (cnt[i] - 1) * (cnt[i] - 2) ) / 6; //(조합론)
        ans %= 1000000007;
    }
    cout << ans;
}
