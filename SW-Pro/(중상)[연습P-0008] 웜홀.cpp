#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

bool isCycle;
int nodeCnt, caseCnt, minusCnt;
int dist[501];
vector<pair<int, int>> v[501];

void bellmanFord() {

	dist[1] = 0;

	bool isUpdated = false;

	// ��������Ŭ üũ�� ���� nodeCnt-1���� �ƴ� nodeCnt�� üũ
	for (int i = 1; i <= nodeCnt; i++) {

		isCycle = false;
		isUpdated = false;

		for (int curIdx = 1; curIdx <= nodeCnt; curIdx++) {
			for (pair<int, int> next : v[curIdx]) {

				if (dist[curIdx] == INT_MAX) continue;

				int nextIdx = next.first;
				int nextDist = next.second;

				if (dist[nextIdx] > dist[curIdx] + nextDist) {
					dist[nextIdx] = dist[curIdx] + nextDist;
					isUpdated = true;

					if (i == nodeCnt) isCycle = true;
				}
			}
		}


		// �ѹ����� ���Ҵµ��� ���̻� �ִܰ�� ������ �Ͼ�� ������ ���� ����
		if (!isUpdated) break;
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T = 0;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {

		cin >> nodeCnt >> caseCnt >> minusCnt;

		fill(dist, dist + 501, INT_MAX);
		for (int i = 0; i < 501; i++) {
			v[i].clear();
		}


		for (int i = 0; i < caseCnt; i++) {
			int from = 0; int to = 0; int dist = 0;
			cin >> from >> to >> dist;

			// M���� ������� ��
			v[from].push_back({ to, dist });
			v[to].push_back({ from, dist });
		}


		for (int i = 0; i < minusCnt; i++) {
			int from = 0; int to = 0; int dist = 0;
			cin >> from >> to >> dist;
			v[from].push_back({ to, (dist * -1) });
		}

		bellmanFord();

		if (isCycle)
			cout << "#" << tc << " " << "YES" << '\n';
		else
			cout << "#" << tc << " " << "NO" << '\n';
	}
	return 0;

}