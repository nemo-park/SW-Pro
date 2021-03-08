#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

struct house {
	int row;
	int col;
};
queue<house> q;

int S;

int arr[26][26];
int dr[4] = { 0, 1, 0, -1 };
int dc[4] = { 1, 0, -1, 0 };

struct compare {
	bool operator()(int& a, int& b) {
		return a > b;
	}
};
priority_queue<int, vector<int>, compare> pq;
bool visited[26][26];

int BFS(int r, int c) {

	int result = 0;

	visited[r][c] = true;
	q.push({ r, c });
	result++;

	for (int i = 0; i < 4; i++) {

		if (r + dr[i] < 0 || c + dc[i] < 0 || S <= r + dr[i] || S <= c + dc[i])
			continue;

		visited[r + dr[i]][c + dc[i]] = true;

		if (arr[r + dr[i]][c + dc[i]] == 1) {
			q.push({ r + dr[i], c + dc[i] });
			result++;
		}
	}

	while (!q.empty()) {

		int curRow = q.front().row;
		int curCol = q.front().col;
		q.pop();

		for (int i = 0; i < 4; i++) {

			if (curRow + dr[i] < 0 || curCol + dc[i] < 0 || S <= curRow + dr[i] || S <= curCol + dc[i])
				continue;

			if (visited[curRow + dr[i]][curCol + dc[i]])
				continue;

			visited[curRow + dr[i]][curCol + dc[i]] = true;

			if (arr[curRow + dr[i]][curCol + dc[i]] == 1) {
				q.push({ curRow + dr[i], curCol + dc[i] });
				result++;
			}
		}
	}

	return result;
}

int main() {

	cin >> S;

	for (int i = 0; i < S; i++) {

		string s = "";
		cin >> s;

		for (int j = 0; j < S; j++) {
			arr[i][j] = s.at(j) - '0';
		}
	}

	for (int i = 0; i < S; i++) {
		for (int j = 0; j < S; j++) {
			if (arr[i][j] == 1 && !visited[i][j]) {
				pq.push(BFS(i, j));
			}
		}
	}

	cout << pq.size() << '\n';
	while (!pq.empty()) {
		cout << pq.top() << '\n';
		pq.pop();
	}

	return 0;
}
