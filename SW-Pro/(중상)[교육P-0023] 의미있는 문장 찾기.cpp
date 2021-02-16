#include <iostream>
#include <string>
#include <cstring>
#include <climits>
#include <algorithm>
using namespace std;

int totCnt, mCnt, result;
int arr[1000001];
int visited[1000001];

int twoPointer() {

	int start = 0;
	int end = 0;
	int match = 0;
	int usedCnt = 0;
	int minVal = INT_MAX;

	while (start <= end && end <= totCnt) {

		if (match < mCnt) {
			if (visited[arr[end]] == 0) match++;

			usedCnt++;
			visited[arr[end++]]++;
		}
		else if (match == mCnt) {

			minVal = min(usedCnt, minVal);

			if (visited[arr[start]] == 1) match--;

			usedCnt--;
			visited[arr[start++]]--;
		}
	}

	if (minVal == INT_MAX) return -1;
	else return minVal;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T = 0;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {

		cin >> totCnt >> mCnt;

		result = 0;
		memset(arr, 0, sizeof(arr));
		memset(visited, 0, sizeof(visited));

		for (int i = 0; i < totCnt; i++) {
			cin >> arr[i];
		}

		cout << "#" << tc << " " << twoPointer() << '\n';
	}
	return 0;
}