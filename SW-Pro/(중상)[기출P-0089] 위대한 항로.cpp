#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 987654321
#define MAX_N 100001
using namespace std;

struct compare {
	bool operator()(pair<int, int>& a, pair<int, int>& b) {
		return a.second > b.second;
	}
};
priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;

int dist[MAX_N];
int fArr[MAX_N];
vector<pair<int, int>> v[MAX_N];

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

			// 정방향 다익스트라 : 누적합 < 친구식량인 경우, 음수가 나오는데
			// 다음 값에 따라 무조건 0으로 치환이 불가하므로 정방향 다익스트라 사용 불가
			// 역방향 다익스트라 : 누적합 < 친구식량인 경우, 음수가 나오는데
			// 이 값을 0으로 치환 후 계산이 가능하므로 사용 가능!
			int chk = dist[curIdx] + nextDist - fArr[nextIdx];
			if (chk < 0)
				chk = 0;
			else
				chk = dist[curIdx] + nextDist - fArr[nextIdx];

			if (dist[nextIdx] > chk) {
				dist[nextIdx] = chk;
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

		memset(fArr, 0, sizeof(fArr));
		fill(dist, dist + MAX_N, INF);
		for (int i = 0; i < MAX_N; i++) {
			v[i].clear();
		}

		int nodeCnt = 0; int caseCnt = 0; int fCnt = 0;
		cin >> nodeCnt >> caseCnt >> fCnt;

		for (int i = 0; i < caseCnt; i++) {
			int from = 0; int to = 0; int dist = 0;
			cin >> from >> to >> dist;
			v[to].push_back({ from, dist });
		}

		for (int i = 0; i < fCnt; i++) {
			int to = 0; int dist = 0;
			cin >> to >> dist;
			fArr[to] = dist;
		}

		dijkstra(nodeCnt);

		cout << "#" << tc << " " << dist[1] << '\n';
	}
	return 0;
}