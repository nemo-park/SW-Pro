#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#define MAX_N 101
using namespace std;

bool visited[MAX_N];
vector<int> v[MAX_N];
queue<int> q;

void BFS() {
	q.push(1);
	visited[1] = true;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int next : v[cur]) {
			if (visited[next]) continue;

			q.push(next);
			visited[next] = true;
		}
	}
}

int main() {

	int nodeCnt = 0; cin >> nodeCnt;
	int caseCnt = 0; cin >> caseCnt;

	for (int i = 0; i < caseCnt; i++) {
		int from = 0; int to = 0;
		cin >> from >> to;
		v[from].push_back(to);
		v[to].push_back(from);
	}

	BFS();

	int ans = 0;
	for (int i = 1; i <= nodeCnt; i++) {
		if (visited[i]) ans++;
	}

	cout << ans - 1 << '\n';

	return 0;
}
