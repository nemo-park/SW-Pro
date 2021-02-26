#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#define MAX_N 501
#define INF 987654321
using namespace std;

struct node {
	int x;
	int y;
	int dist;
};
struct compare {
	bool operator()(node& a, node& b) {
		return a.dist > b.dist;
	}
};
priority_queue<node, vector<node>, compare> pq;

int row, col;
int dist[MAX_N][MAX_N];
int arr[MAX_N][MAX_N];

// µ¿ ³² ¼­ ºÏ
int dr[4] = { 0, 1, 0, -1 };
int dc[4] = { 1, 0, -1, 0 };

void dijkstra() {

	pq.push({ 0, 0, arr[0][0] });
	dist[0][0] = arr[0][0];

	while (!pq.empty()) {

		int curX = pq.top().x;
		int curY = pq.top().y;
		int curDist = pq.top().dist;
		pq.pop();

		if (dist[curX][curY] < curDist) continue;

		for (int i = 0; i < 4; i++) {
			int nextX = curX + dr[i];
			int nextY = curY + dc[i];
			int nextDist = arr[nextX][nextY];

			if (nextX < 0 || nextY < 0 || nextX == row || nextY == col)
				continue;

			if (dist[nextX][nextY] > dist[curX][curY] + nextDist) {
				dist[nextX][nextY] = dist[curX][curY] + nextDist;
				pq.push({ nextX, nextY, dist[nextX][nextY] });
			}
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

		memset(arr, 0, sizeof(arr));
		for (int i = 0; i < MAX_N; i++) {
			for (int j = 0; j < MAX_N; j++) {
				dist[i][j] = INF;
			}
		}

		cin >> row >> col;
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				cin >> arr[i][j];
			}
		}

		dijkstra();

		cout << "#" << tc << " " << dist[row - 1][col - 1] << '\n';
	}
	return 0;
}