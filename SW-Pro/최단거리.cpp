#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 987654321
#define MAX_N 10001
using namespace std;

int N, M, S, E;
vector<int> v[MAX_N];
int dist[MAX_N];
queue<int> q;

void dijkstra(int start) {
	q.push(start);
	dist[start] = 0;

	while (!q.empty()) {
		int curIdx = q.front();
		q.pop();

		if (curIdx == E) break;

		for (int nextIdx : v[curIdx]) {
			if (dist[nextIdx] > dist[curIdx] + 1) {
				dist[nextIdx] = dist[curIdx] + 1;
				q.push(nextIdx);
			}
		}
	}
}

int main() {

	cin >> N >> M;

	fill(dist, dist + MAX_N, INF);

	for (int i = 0; i < M; i++) {
		int from = 0; int to = 0;
		cin >> from >> to;

		v[from].push_back(to);
		v[to].push_back(from);
	}

	cin >> S >> E;

	dijkstra(S);

	cout << dist[E] << '\n';

	return 0;
}