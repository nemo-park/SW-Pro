#include <iostream>
#include <string>
#include <cstring>
#include <queue>
using namespace std;

int visited[201][201];
int N, uRow, uCol, pRow, pCol;
int dr[8] = { -1, -2, -2, -1, 1, 2, 2, 1 };
int dc[8] = { -2, -1, 1, 2, -2, -1, 1, 2 };

int bfs(int cnt) {
	// 1. Queue ����
	queue<pair<int, int>> q;
	// 2. �������� QueueҮ ����
	q.push(make_pair(uRow, uCol));
	// 3. ������ �湮 üũ
	visited[uRow][uCol] = 1;

	// 4. while �� ����
	while (!q.empty()) {
		// 4. while �� ���� - ������
		int curRow = q.front().first;
		int curCol = q.front().second;
		q.pop();

		for (int i = 0; i < 8; i++) {
			for (int j = 1; j <= cnt; j++) {
				int nextRow = curRow + dr[i] * j;
				int nextCol = curCol + dc[i] * j;

				if (nextRow == pRow && nextCol == pCol) {
					return visited[curRow][curCol];
				}

				// 4-1. Ż������ : ���� �������
				if (nextRow < 1 || nextRow > N || nextCol < 1 || nextCol > N) continue;
				// 4-2. Ż������ : �湮�� ������
				if (visited[nextRow][nextCol] > 0) continue;
				// 4. while �� - �湮 üũ
				visited[nextRow][nextCol] = visited[curRow][curCol] + 1;
				// 4. while �� - ���ο� ������ QueueҮ ����
				q.push(make_pair(nextRow, nextCol));
			}
		}
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc = 0;
	cin >> tc;

	for (int i = 1; i <= tc; i++) {
		cin >> N >> uRow >> uCol >> pRow >> pCol;

		memset(visited, 0, sizeof(visited));
		int pCnt = bfs(1);
		memset(visited, 0, sizeof(visited));
		int uCnt = bfs(3);
		cout << "#" << i << " " << pCnt - uCnt << '\n';
	}

	return 0;
}