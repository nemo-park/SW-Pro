#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#define MAX_N 100001
using namespace std;

int nCnt, qCnt;
int minTree[MAX_N * 4];
int maxTree[MAX_N * 4];

void update(int idx, int val) {

	minTree[idx] = val;
	maxTree[idx] = val;
	idx /= 2;

	while (idx > 0) {
		minTree[idx] = min(minTree[idx * 2], minTree[idx * 2 + 1]);
		maxTree[idx] = max(maxTree[idx * 2], maxTree[idx * 2 + 1]);
		idx /= 2;
	}
}

int getMin(int s, int e) {

	int ans = 111111;

	while (s <= e) {
		if (s % 2 == 1) ans = min(ans, minTree[s]);
		if (e % 2 == 0) ans = min(ans, minTree[e]);

		s = (s + 1) / 2;
		e = (e - 1) / 2;
	}
	return ans;
}

int getMax(int s, int e) {

	int ans = 0;

	while (s <= e) {
		if (s % 2 == 1) ans = max(ans, maxTree[s]);
		if (e % 2 == 0) ans = max(ans, maxTree[e]);

		s = (s + 1) / 2;
		e = (e - 1) / 2;
	}
	return ans;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T = 0;
	cin >> T;
	
	for (int tc = 1; tc <= T; tc++) {

		int minSum = 0;
		int maxSum = 0;
		memset(minTree, 0, sizeof(minTree));
		memset(maxTree, 0, sizeof(maxTree));

		cin >> nCnt >> qCnt;

		int leafSize = 1;

		while (leafSize < nCnt) {
			leafSize <<= 1;
		}

		for (int i = 0; i < nCnt; i++) {
			int num = 0;
			cin >> num;
			minTree[leafSize + i] = num;
			maxTree[leafSize + i] = num;
		}

		for (int i = leafSize - 1; i > 0; i--) {
			minTree[i] = min(minTree[i * 2], minTree[i * 2 + 1]);
			maxTree[i] = max(maxTree[i * 2], maxTree[i * 2 + 1]);
		}

		for (int i = leafSize + nCnt; i < 2 * leafSize; i++) {
			minTree[i] = 111111;
		}

		for (int i = 0; i < qCnt; i++) {
			int chk = 0; int a = 0; int b = 0;
			cin >> chk >> a >> b;

			if (chk == 1)
				update(leafSize - 1 + a, b);
			else {
				minSum += getMin(leafSize - 1 + a, leafSize - 1 + b);
				maxSum += getMax(leafSize - 1 + a, leafSize - 1 + b);
			}
		}

		cout << "#" << tc << " " << maxSum << " " << minSum << '\n';

	}

	return 0;
}