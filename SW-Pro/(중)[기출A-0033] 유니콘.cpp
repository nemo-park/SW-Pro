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
	// 1. Queue 생성
	queue<pair<int, int>> q;
	// 2. 시작점을 Queue內 삽입
	q.push(make_pair(uRow, uCol));
	// 3. 시작점 방문 체크
	visited[uRow][uCol] = 1;

	// 4. while 문 시작
	while (!q.empty()) {
		// 4. while 문 시작 - 꺼내고
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

				// 4-1. 탈출조건 : 맵을 벗어났는지
				if (nextRow < 1 || nextRow > N || nextCol < 1 || nextCol > N) continue;
				// 4-2. 탈출조건 : 방문한 곳인지
				if (visited[nextRow][nextCol] > 0) continue;
				// 4. while 문 - 방문 체크
				visited[nextRow][nextCol] = visited[curRow][curCol] + 1;
				// 4. while 문 - 새로운 방향을 Queue內 삽입
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