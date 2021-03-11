#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 987654321
#define MAX_N 1001
using namespace std;

int nodeCnt, caseCnt, partyNo;

vector<pair<int, int>> v_go[MAX_N];
vector<pair<int, int>> v_return[MAX_N];
int dist_go[MAX_N];
int dist_return[MAX_N];

struct compare {
	bool operator()(pair<int, int>& a, pair<int, int>& b) {
		return a.second > b.second;
	}
};
priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;

void dijkstra_go() {

	fill(dist_go, dist_go + MAX_N, INF);
	pq.push({ partyNo, 0 });
	dist_go[partyNo] = 0;

	while (!pq.empty()) {
		int curIdx = pq.top().first;
		int curDist = pq.top().second;
		pq.pop();

		if (dist_go[curIdx] < curDist) continue;

		for (pair<int, int> next : v_go[curIdx]) {
			int nextIdx = next.first;
			int nextDist = next.second;

			if (dist_go[nextIdx] > dist_go[curIdx] + nextDist) {
				dist_go[nextIdx] = dist_go[curIdx] + nextDist;
				pq.push({ nextIdx, dist_go[nextIdx] });
			}
		}
	}
}

void dijkstra_return() {

	fill(dist_return, dist_return + MAX_N, INF);
	pq.push({ partyNo, 0 });
	dist_return[partyNo] = 0;

	while (!pq.empty()) {
		int curIdx = pq.top().first;
		int curDist = pq.top().second;
		pq.pop();

		if (dist_return[curIdx] < curDist) continue;

		for (pair<int, int> next : v_return[curIdx]) {
			int nextIdx = next.first;
			int nextDist = next.second;

			if (dist_return[nextIdx] > dist_return[curIdx] + nextDist) {
				dist_return[nextIdx] = dist_return[curIdx] + nextDist;
				pq.push({ nextIdx, dist_return[nextIdx] });
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> nodeCnt >> caseCnt >> partyNo;

	for (int i = 0; i < caseCnt; i++) {
		int from = 0; int to = 0; int d = 0;
		cin >> from >> to >> d;

		v_go[to].push_back({ from, d });
		v_return[from].push_back({ to, d });
	}

	dijkstra_go();
	dijkstra_return();

	int ans = 0;
	for (int i = 1; i <= nodeCnt; i++) {
		ans = max(ans, dist_go[i] + dist_return[i]);
	}

	cout << ans << '\n';

	return 0;
}
