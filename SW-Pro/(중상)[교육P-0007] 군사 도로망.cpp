#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

int parent[100001];

struct edge {
	int from;
	int to;
	int cost;
};

struct compare {
	bool operator()(edge& e1, edge& e2) {
		return e1.cost > e2.cost;
	}
};

int findParent(int a) {
	if (parent[a] == a) return parent[a];
	return parent[a] = findParent(parent[a]);
}

void unionParent(int a, int b) {

	int aRoot = findParent(a);
	int bRoot = findParent(b);

	if (aRoot == bRoot) return;

	if (aRoot < bRoot) parent[bRoot] = aRoot;
	else parent[aRoot] = bRoot;

}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T = 0;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {

		int totCnt = 0;	int delCnt = 0;	int addCnt = 0;
		cin >> totCnt >> delCnt >> addCnt;

		memset(parent, 0, sizeof(parent));

		priority_queue<edge, vector<edge>, compare> pq;

		long long result = 0;

		// Initialize
		for (int i = 1; i <= totCnt; i++) {
			parent[i] = i;
		}

		// ö�ź���� ���̵�� ���δ� ���� X
		// ö�Ž�
		for (int i = 0; i < delCnt; i++) {
			int a = 0;	int b = 0;	int cost = 0;
			cin >> a >> b >> cost;

			// ũ�罺Į �����鼭 ���ô���� cost �� ���� ö�Ŵ�� cost �� ����� ���� 
			result += cost;

			// ö�ź���� ���� ó���Ͽ� ����
			// �������� �����ϸ� -4 > -2 > -1 ������ ���� �տ� ��ġ�ϰ� �ǹǷ� 
			// ö�ź���� ū ����� ���õ��� ����
			pq.push({ a, b, (cost * -1) });
		}

		// �Ǽ��� 
		for (int i = 0; i < addCnt; i++) {
			int a = 0;	int b = 0;	int cost = 0;
			cin >> a >> b >> cost;
			pq.push({ a, b, cost });
		}

		int selectCnt = 0;
		for (int i = 0; i < delCnt + addCnt; i++) {

			// ������ = N �� ��, Spanning Tree ������ = N - 1
			if (selectCnt == totCnt - 1)	break;

			int from = pq.top().from;
			int to = pq.top().to;
			int cost = pq.top().cost;
			pq.pop();

			// ����Ŭ�� �߻��ؼ� �ȵ�
			if (findParent(from) != findParent(to)) {
				result += cost;
				selectCnt++;
				unionParent(from, to);
			}
		}

		cout << "#" << tc << " " << result << '\n';
	}

	return 0;

}