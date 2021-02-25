#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#define MAX_N 1001
#define INF 987654321
using namespace std;

struct compare {
	bool operator()(pair<int, int>& a, pair<int, int>& b) {
		return a.second > b.second;
	}
};
priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;

int dist[MAX_N];
vector<pair<int, int>> v[MAX_N];

void dijkstra(int S, int E) {

	pq.push({ S, 0 });
	dist[S] = 0;

	while (!pq.empty()) {

		int curIdx = pq.top().first;
		int curDist = pq.top().second;
		pq.pop();

		if (curIdx == E) break;

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

	fill(dist, dist + MAX_N, INF);

	int nodeCnt = 0;	cin >> nodeCnt;
	int caseCnt = 0;	cin >> caseCnt;

	for (int i = 0; i < caseCnt; i++) {
		int from = 0; int to = 0; int dist = 0;
		cin >> from >> to >> dist;
		v[from].push_back({ to, dist });
	}

	int S = 0; int E = 0;
	cin >> S >> E;

	dijkstra(S, E);

	cout << dist[E] << '\n';

	return 0;
}