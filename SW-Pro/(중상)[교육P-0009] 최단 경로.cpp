#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>
#define MAX_N 100001
using namespace std;

struct compare {
	bool operator()(pair<int, int>& a, pair<int, int>& b) {
		return a.second > b.second;
	}
};
priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;

vector<pair<int, int>> v[MAX_N];
int dist[MAX_N];

void dijkstra(int idx) {

	pq.push({ idx, 0 });
	// 시작점 0으로 초기화
	dist[idx] = 0;

	while (!pq.empty()) {

		int curIdx = pq.top().first;
		int curDist = pq.top().second;
		pq.pop();

		// 지금 꺼낸 것보다 더 짧은 경로를 알고있다면, 지금 꺼낸 것 무시
		if (dist[curIdx] < curDist) continue;


		// 인접한 정점 모두 검사
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

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T = 0;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {

		int nodeCnt = 0;	 int caseCnt = 0;
		cin >> nodeCnt >> caseCnt;

		fill(dist, dist + MAX_N, INT_MAX);
		for (int i = 1; i <= MAX_N; i++) {
			for (int i = 1; i <= MAX_N; i++) {
			v[i].clear();
		}

		for (int i = 0; i < caseCnt; i++) {
			int a = 0;	int b = 0;	int d = 0;
			cin >> a >> b >> d;
			v[a].push_back({ b, d });
			v[b].push_back({ a, d });
		}

		dijkstra(1);

		if (dist[nodeCnt] != INT_MAX) {
			cout << "#" << tc << " " << dist[nodeCnt] << '\n';
		}
		else {
			cout << "#" << tc << " " << -1 << '\n';
		}

	}

	return 0;

}