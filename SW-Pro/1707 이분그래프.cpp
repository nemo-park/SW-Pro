#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#define MAX_N 20001
using namespace std;

vector<int> v[MAX_N];
int arr[MAX_N];
queue<int> q;
bool ans;

void BFS(int start) {

	q.push(start);
	arr[start] = 1;

	while (!q.empty()) {

		int cur = q.front();
		q.pop();

		for (int next : v[cur]) {

			if (arr[next] == arr[cur]) {
				ans = false;

				while (!q.empty()) {
					q.pop();
				}

				break;
			}

			if (arr[next] > 0) continue;

			if (arr[cur] == 1) arr[next] = 2;
			else arr[next] = 1;

			q.push(next);

		}
	}
}

int main() {

	int T = 0;
	cin >> T;
	for (int tc = 0; tc < T; tc++) {

		memset(arr, 0, sizeof(arr));
		for (int i = 0; i < MAX_N; i++) {
			v[i].clear();
		}
		ans = true;

		int nodeCnt = 0; int caseCnt = 0;
		cin >> nodeCnt >> caseCnt;

		for (int i = 0; i < caseCnt; i++) {
			int from = 0; int to = 0;
			cin >> from >> to;
			v[from].push_back(to);
			v[to].push_back(from);
		}

		// 1번 노드에서 모든 노드까지 탐색이 불가할 경우 대비
		for (int i = 1; i <= nodeCnt; i++) {
			if (arr[i] == 0) BFS(i);
		}

		if (ans) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}

	return 0;
}
