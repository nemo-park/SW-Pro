#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#define MAX_N 50001
using namespace std;

int depth[MAX_N];
int parent[MAX_N][21];

vector<int> v[MAX_N];

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

	// 1. a ��尡 �׻� �����ִٰ� ����
	if (depth[a] > depth[b]) swap(a, b);

	
	// 2. ���� ����� depth ���߱� (B�� A�� �ִ� depth���� ����ø�)
	for (int i = 20; i >= 0; i--) {
		if (depth[b] - depth[a] >= (1 << i)) {
			b = parent[b][i];
		}
	}

	// 3. ���� ��ġ�� LCA �� ���
	if (a == b)	return a;


	// 4. ������ ���ÿ� 2�������� ����ø� �� �ִµ����� ����ø�
	//    ��, �θ� �ٸ���� �̵�
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

	memset(depth, -1, sizeof(depth));
	memset(parent, 0, sizeof(parent));

	int nodeCnt = 0;
	cin >> nodeCnt;

	for (int i = 0; i < nodeCnt - 1; i++) {
		int a = 0;	int b = 0;
		cin >> a >> b;

		// �������� ������, �ڽĳ�尡 �������� �� �����Ƿ� 
		// ���������� �����ϴ� ���Ϳ� �ѹ��� �ٲ㼭 ����
		v[a].push_back(b);
		v[b].push_back(a);
	}

	bfs(1);

	for (int k = 1; k < 21; k++) {
		for (int a = 1; a <= nodeCnt; a++) {
			parent[a][k] = parent[parent[a][k - 1]][k - 1];
		}
	}

	int caseCnt = 0;
	cin >> caseCnt;
	for (int i = 0; i < caseCnt; i++) {
		int a = 0;	int b = 0;
		cin >> a >> b;
		cout << lca(a, b) << '\n';
	}

	return 0;

}