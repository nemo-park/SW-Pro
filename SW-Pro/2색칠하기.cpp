#include <iostream>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#define MAX_N 10001

using namespace std;
int N, M;
bool ans;
bool visited[MAX_N];
int depth[MAX_N];
vector<int> v[MAX_N];
queue<int> q;

void BFS() {

	depth[0] = 1;

	q.push(0);
	visited[0] = true;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int next : v[cur]) {

			if (depth[next] == depth[cur]) {
				ans = false;
				while (!q.empty()) {
					q.pop();
				}
				break;
			}
			else {
				if (visited[next]) continue;

				depth[next] = depth[cur] + 1;
				q.push(next);
				visited[next] = true;
			}
		}
	}
}

int main() {

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int from = 0; int to = 0;
		cin >> from >> to;

		v[from].push_back(to);
		v[to].push_back(from);
	}

	ans = true;

	BFS();

	if (ans) cout << "YES" << '\n';
	else cout << "NO" << '\n';

	return 0;
}
