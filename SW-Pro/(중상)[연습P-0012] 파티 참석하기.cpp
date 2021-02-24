#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <climits>
#include <vector>
#include <queue>
#define MAX_N 50001
using namespace std;

struct compare {
	bool operator()(pair<int, int>& a, pair<int, int>& b) {
		return a.second > b.second;
	}
};

priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;

int nodeCnt, caseCnt, roomNo;

int distGo[MAX_N];
int distReturn[MAX_N];
vector<pair<int, int>> vGo[MAX_N];
vector<pair<int, int>> vReturn[MAX_N];

void dijkstraGo(int idx) {

	pq.push({ idx, 0 });
	distGo[idx] = 0;

	while (!pq.empty()) {

		int curIdx = pq.top().first;
		int curDist = pq.top().second;
		pq.pop();

		if (distGo[curIdx] < curDist) continue;

		for (pair<int, int> next : vGo[curIdx]) {

			int nextIdx = next.first;
			int nextDist = next.second;

			if (distGo[nextIdx] > distGo[curIdx] + nextDist) {
				distGo[nextIdx] = distGo[curIdx] + nextDist;
				pq.push({ nextIdx, distGo[nextIdx] });
			}
		}
	}
}


void dijkstraReturn(int idx) {

	pq.push({ idx, 0 });
	distReturn[idx] = 0;

	while (!pq.empty()) {

		int curIdx = pq.top().first;
		int curDist = pq.top().second;
		pq.pop();

		if (distReturn[curIdx] < curDist) continue;

		for (pair<int, int> next : vReturn[curIdx]) {

			int nextIdx = next.first;
			int nextDist = next.second;

			if (distReturn[nextIdx] > distReturn[curIdx] + nextDist) {
				distReturn[nextIdx] = distReturn[curIdx] + nextDist;
				pq.push({ nextIdx, distReturn[nextIdx] });
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

		cin >> nodeCnt >> caseCnt >> roomNo;
		fill(distGo, distGo + MAX_N, INT_MAX);
		fill(distReturn, distReturn + MAX_N, INT_MAX);
		for (int i = 0; i < MAX_N; i++) {
			vGo[i].clear();
			vReturn[i].clear();
		}

		for (int i = 0; i < caseCnt; i++) {

			int from = 0; int to = 0; int d = 0;
			cin >> from >> to >> d;

			// 돌아오는길 최단거리용
			vReturn[from].push_back({ to, d });

			// 가는길 최단거리용
			vGo[to].push_back({ from, d });
		}

		int maxVal = 0;

		dijkstraReturn(roomNo);
		dijkstraGo(roomNo);

		for (int i = 1; i <= nodeCnt; i++) {
			maxVal = max(maxVal, distGo[i] + distReturn[i]);
		}

		cout << "#" << tc << " " << maxVal << '\n';
	}

	return 0;

}