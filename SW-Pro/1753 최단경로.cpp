#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#define MAX_V 20001
#define INF 987654321
using namespace std;

struct compare {
	bool operator()(pair<int, int>& a, pair<int, int>& b) {
		return a.second > b.second;
	}
};
priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;

int dist[MAX_V];
vector<pair<int, int>> v[MAX_V];

void dijkstra(int idx) {

	pq.push({ idx, 0 });
	dist[idx] = 0;

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

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	fill(dist, dist + MAX_V, INF);

	int nodeCnt = 0; int caseCnt = 0;
	cin >> nodeCnt >> caseCnt;

	int startIdx = 0;
	cin >> startIdx;

	for (int i = 0; i < caseCnt; i++) {
		int from = 0; int to = 0; int dist = 0;
		cin >> from >> to >> dist;
		v[from].push_back({ to, dist });
	}

	dijkstra(startIdx);

	for (int i = 1; i <= nodeCnt; i++) {
		if (dist[i] == INF)
			cout << "INF" << '\n';
		else
			cout << dist[i] << '\n';
	}

	return 0;

}