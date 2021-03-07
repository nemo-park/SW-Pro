#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#define MAX_N 1001
using namespace std;

int N, M, S;

vector<int> v[MAX_N];
bool visited[MAX_N];
queue<int> q;

void DFS(int cur) {

	visited[cur] = true;
	cout << cur << " ";

	for (int next : v[cur]) {

		if (visited[next]) continue;
		DFS(next);
	}
}

void BFS(int idx) {

	visited[idx] = true;
	q.push(idx);

	while (!q.empty()) {

		int cur = q.front();
		cout << cur << " ";
		q.pop();

		for (int next : v[cur]) {
			if (visited[next]) continue;
			visited[next] = true;
			q.push(next);
		}
	}
}

int main() {

	cin >> N >> M >> S;

	for (int i = 0; i < M; i++) {

		int from = 0; int to = 0;
		cin >> from >> to;

		v[from].push_back(to);
		v[to].push_back(from);
	}

	for (int i = 0; i < N; i++) {
		sort(v[i].begin(), v[i].end());
	}

	memset(visited, false, sizeof(visited));
	DFS(S);
	cout << '\n';

	memset(visited, false, sizeof(visited));
	BFS(S);
	cout << '\n';

	return 0;
}