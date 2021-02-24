#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#define MAX_N 100001
using namespace std;

vector<int> v[MAX_N];
int depth[MAX_N];
int parent[MAX_N][21];

void bfs(int idx) {

	queue<int> q;
	q.push(idx);
	depth[idx] = 0;

	while (!q.empty()) {

		int curIdx = q.front();
		q.pop();

		for (int nextIdx : v[curIdx]) {

			if (depth[nextIdx] == -1) {
				depth[nextIdx] = depth[curIdx] + 1;
				parent[nextIdx][0] = curIdx;
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


		for (int i = 1; i <= nodeCnt - 1; i++) {
			int a = 0;
			cin >> a;
			v[a].push_back(i + 1);
		}

		bfs(1);

		for (int k = 1; k < 20; k++) {
			for (int a = 1; a <= nodeCnt; a++) {
				parent[a][k] = parent[parent[a][k - 1]][k - 1];
			}
		}


		cout << "#" << tc << " ";
		for (int i = 0; i < caseCnt; i++) {
			int a = 0;	int b = 0;
			cin >> a >> b;
			cout << lca(a, b) << " ";
		}
		cout << '\n';

	}

	return 0;
}