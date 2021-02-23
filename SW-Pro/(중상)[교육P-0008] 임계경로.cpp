#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#define MAX_N 100001
using namespace std;

vector<pair<int, int>> v[MAX_N];
int indegree[MAX_N];
int cost[MAX_N];

void bfs() {

	int from = 1;

	queue<int> q;
	q.push(from);

	while (!q.empty()) {

		from = q.front();
		q.pop();

		for (pair<int, int> chk : v[from]) {
			int to = chk.first;
			indegree[to]--;

			// 진입차수 = 0 이면, Queue 에 추가
			if (indegree[to] == 0)
				q.push(to);

			int c = chk.second;

			// 가장 오래걸리는 작업에 대한 Cost 처리
			cost[to] = max(cost[to], cost[from] + c);

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

		int totCnt = 0;		int caseCnt = 0;
		cin >> totCnt >> caseCnt;

		// 초기화 ================================
		memset(indegree, 0, sizeof(indegree));
		memset(cost, 0, sizeof(cost));
		for (int i = 0; i < MAX_N; i++) {
			v[i].clear();
		}

		for (int i = 0; i < caseCnt; i++) {
			int from = 0; int to = 0; int cost = 0;
			cin >> from >> to >> cost;

			v[from].push_back({ to, cost });
			indegree[to]++;
		}

		bfs();

		cout << "#" << tc << " " << cost[totCnt] << '\n';
	}

	return 0;
}