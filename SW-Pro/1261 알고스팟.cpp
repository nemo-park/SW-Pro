#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;

struct node {
	int r;
	int c;
	int dist;
};

struct compare {
	bool operator()(node& a, node& b) {
		return a.dist > b.dist;
	}
};
priority_queue<node, vector<node>, compare> pq;

int colM, rowN;
int arr[101][101];
int dist[101][101];

int dr[4] = { 1, 0, -1, 0 };
int dc[4] = { 0, 1, 0, -1 };

void dijkstra() {

	pq.push({ 0, 0, 0 });
	dist[0][0] = 0;

	while (!pq.empty()) {
		int curRow = pq.top().r;
		int curCol = pq.top().c;
		int curDist = pq.top().dist;
		pq.pop();

		if (curRow == (rowN - 1) && curCol == (colM - 1)) break;

		if (dist[curRow][curCol] < curDist) continue;

		for (int i = 0; i < 4; i++) {
			int nextRow = curRow + dr[i];
			int nextCol = curCol + dc[i];
			int nextDist = arr[nextRow][nextCol];

			if (nextRow < 0 || nextCol < 0 || nextRow == rowN || nextCol == colM)
				continue;

			if (dist[nextRow][nextCol] > dist[curRow][curCol] + nextDist) {
				dist[nextRow][nextCol] = dist[curRow][curCol] + nextDist;
				pq.push({ nextRow, nextCol, dist[nextRow][nextCol] });
			}
		}
	}
}


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			dist[i][j] = INF;
		}
	}

	cin >> colM >> rowN;

	for (int i = 0; i < rowN; i++) {
		string str;
		cin >> str;

		for (int j = 0; j < colM; j++) {
			arr[i][j] = str[j] - '0';
		}
	}

	dijkstra();

	cout << dist[rowN - 1][colM - 1] << '\n';


	return 0;

}