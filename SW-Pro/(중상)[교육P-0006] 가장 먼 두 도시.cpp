#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#define INF 987654321
using namespace std;

// N이 작을때만 사용 가능한 알고리즘
int arr[301][301];

void floydWarshall(int nodeCnt) {

	for (int k = 0; k < nodeCnt; k++) {
		for (int i = 0; i < nodeCnt; i++) {
			for (int j = 0; j < nodeCnt; j++) {
				if (arr[i][j] > arr[i][k] + arr[k][j]) {
					arr[i][j] = arr[i][k] + arr[k][j];
				}
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

		int nodeCnt = 0;
		cin >> nodeCnt;

		for (int i = 0; i < nodeCnt; i++) {
			for (int j = 0; j < nodeCnt; j++) {
				cin >> arr[i][j];
			}
		}

		floydWarshall(nodeCnt);

		int maxVal = 0;

		for (int i = 0; i < nodeCnt; i++) {
			for (int j = 0; j < nodeCnt; j++) {
				maxVal = max(maxVal, arr[i][j]);
			}
		}

		cout << "#" << tc << " " << maxVal << '\n';
	}
	return 0;
}