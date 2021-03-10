#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 987654321
#define MAX_N 801
using namespace std;

int N, caseCnt, v1, v2;
vector<pair<int, int>> v[MAX_N];
int dist[MAX_N];
struct compare {
	bool operator()(pair<int, int>& a, pair<int, int>& b) {
		return a.second > b.second;
	}
};
priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;

void dijkstra(int from) {

	fill(dist, dist + MAX_N, INF);
	pq.push({ from, 0 });
	dist[from] = 0;

	while (!pq.empty()) {
		
		int curIdx = pq.top().first;
		int curDist = pq.top().second;
		pq.pop();

		if (dist[curIdx] < curDist) continue;

		for (pair<int, int> next : v[curIdx]) {
			int nextIdx = next.first;
			int nextDist = next.second;

			if (dist[nextIdx] > dist[curIdx] + nextDist) {
				dist[nextIdx] = dist[curIdx] + nextDist;
				pq.push({ nextIdx, dist[nextIdx] });
			}
		}
	}

}

int main() {

	cin >> N >> caseCnt;

	for(int i = 0; i < caseCnt; i++) {
		int from = 0; int to = 0; int d = 0;
		cin >> from >> to >> d;
		
		v[from].push_back({ to, d });
		v[to].push_back({ from, d });
	}

	cin >> v1 >> v2;

	dijkstra(1);
	int StoV1 = dist[v1];
	int StoV2 = dist[v2];

	dijkstra(N);
	int V1toE = dist[v1];
	int V2toE = dist[v2];

	// 양방향그래프이므로 A->B의 거리와 B->A 거리 같음
	dijkstra(v1);
	int V1toV2 = dist[v2];
	
	bool isPossible1 = false;
	if (StoV1 == INF || V1toV2 == INF || V2toE == INF) isPossible1 = false;
	else isPossible1 = true;

	bool isPossible2 = false;
	if (StoV2 == INF || V1toV2 == INF || V1toE == INF) isPossible2 = false;
	else isPossible2 = true;

	if (isPossible1 == false && isPossible2 == false) {
		cout << -1 << '\n';
	}
	else {
		cout << min(StoV1 + V1toV2 + V2toE, StoV2 + V1toV2 + V1toE) << '\n';
	}

	return 0;
}