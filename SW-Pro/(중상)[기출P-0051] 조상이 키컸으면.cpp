#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#define MAX_N 10001
using namespace std;

vector<int> v[MAX_N];
int depth[MAX_N];
int height[MAX_N];
int parent[MAX_N][21];

void bfs() {

	queue<int> q;
	q.push(1);
	depth[1] = 0;
	parent[1][0] = 1;

	while (!q.empty()) {

		int curIdx = q.front();
		q.pop();

		for (int nextIdx : v[curIdx]) {

			if (depth[nextIdx] == -1) {
				depth[nextIdx] = depth[curIdx] + 1;

				parent[nextIdx][0] = curIdx;

				// 공통 조상들 중 가장 키가 컸던 구성원의 키 저장
				height[nextIdx] = max(height[nextIdx], height[curIdx]);

				q.push(nextIdx);
			}
		}
	}
}


int lca(int a, int b) {

	if (depth[a] > depth[b]) swap(a, b);

	for (int i = 20; i >= 0; i--) {
		if (depth[b] - depth[a] >= (1 << i)) {
			b = parent[b][i];
		}
	}

	if (a == b) return a;

	for (int i = 20; i >= 0; i--) {
		if (parent[a][i] != parent[b][i]) {
			a = parent[a][i];
			b = parent[b][i];
		}
	}

	return parent[a][0];

}



int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int T = 0;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {

		int nodeCnt = 0;	int caseCnt = 0;
		cin >> nodeCnt >> caseCnt;

		memset(depth, -1, sizeof(depth));
		memset(parent, 0, sizeof(parent));
		for (int i = 0; i < MAX_N; i++) {
			v[i].clear();
		}


		for (int i = 1; i <= nodeCnt; i++) {
			int p = 0;	int h = 0;
			cin >> p >> h;

			if (p == 0)	height[1] = h;
			else {
				v[p].push_back(i);
				height[i] = h;
			}
		}

		bfs();

		for (int k = 1; k < 21; k++) {
			for (int a = 1; a <= nodeCnt; a++) {
				parent[a][k] = parent[parent[a][k - 1]][k - 1];
			}
		}


		cout << "#" << tc << " ";
		for (int i = 0; i < caseCnt; i++) {
			int cnt = 0;
			cin >> cnt;

			if (cnt == 1) {
				int idx = 0;
				cin >> idx;
				cout << height[idx] << " ";
			}
			else {

				queue<int> qChk;
				for (int j = 1; j <= cnt; j++) {
					int idx = 0;
					cin >> idx;
					qChk.push(idx);
				}

				int a = qChk.front(); qChk.pop();
				int b = qChk.front(); qChk.pop();
				int tempA = lca(a, b);

				while (!qChk.empty()) {
					int tempB = qChk.front();
					qChk.pop();
					tempA = lca(tempA, tempB);
				}

				cout << height[tempA] << " ";

			}
		}
		cout << '\n';
	}

	return 0;

}