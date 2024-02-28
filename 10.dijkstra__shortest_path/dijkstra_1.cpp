// 5972 - 택배 배송
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n, m, from, to,w;
vector<vector<pair<int,int>>> v; // 헛간 그래프
vector<int> map; //최단거리 저장

int dijkstra(){
    int pos, next, dis, ndis;
    priority_queue< pair<int,int>, 
                    vector<pair<int,int>>, 
                    greater<pair<int,int>>> pq; // 최소 힙 우선순위 큐
    map[1] = 0; //시작 정점 0으로 초기화
    pq.push({1,0}); //시작정점-가중치0
    while(!pq.empty()){
        pos = pq.top().first; //현재 정점
        dis = pq.top().second; //현재 정점까지의 거리
        pq.pop(); // 현재 정점은 큐에서 삭제함으로써 방문 처리
        
        for(int i=0; i < v[pos].size(); i++){ //인접 리스트에서 정점의 인접 정점 수만큼 탐색
            next = v[pos][i].first; //인접 정점
            ndis = v[pos][i].second; //현정점에서 인접 정점까지 가중치
            
            if(map[next] > map[pos] + ndis){ //현정점 가중치합+인접 정점까지의 가중치가 작으면
                map[next]= map[pos] + ndis; //갱신
                pq.push({next,ndis}); // 업데이트시켰을 때의 인접 정접으로 우선순위 큐에 대입
            }
        }
    }
    return map[n]; //시작정점에서 출발한 (1에서 n까지)최단거리 최소 가중치 (=최소 여물)
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    v.resize(n+1); //default val is 0
    map.resize(n+1, 987654321); //최대치 세팅 for 최소 갱신
    
    for(int i=0; i<m; i++){
        cin >> from >> to >> w;
        v[from].push_back({to,w});
        v[to].push_back({from,w});
    }
    
    cout << dijkstra();
    return 0;
}
