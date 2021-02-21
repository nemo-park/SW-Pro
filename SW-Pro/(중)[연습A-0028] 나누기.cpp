#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int zeroCnt, oneCnt;
int arr[129][129];

bool fullScan(int row, int col, int arrSize) {

	int base = arr[row][col];

	for (int i = 0; i < arrSize; i++) {
		for (int j = 0; j < arrSize; j++) {
			if (arr[row + i][col + j] != base) {
				return false;
			}
		}
	}

	return true;
}

void getCnt(int row, int col, int arrSize) {

	int base = arr[row][col];

	if (fullScan(row, col, arrSize)) {
		if (base == 0) zeroCnt++;
		else oneCnt++;
	}
	else {
		arrSize >>= 1;

		getCnt(row, col, arrSize);
		getCnt(row, col + arrSize, arrSize);
		getCnt(row + arrSize, col, arrSize);
		getCnt(row + arrSize, col + arrSize, arrSize);
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T = 0;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		int arrSize = 0;
		cin >> arrSize;

		zeroCnt = 0;	oneCnt = 0;
		memset(arr, 0, sizeof(arr));

		for (int i = 0; i < arrSize; i++) {
			for (int j = 0; j < arrSize; j++) {
				cin >> arr[i][j];
			}
		}

		getCnt(0, 0, arrSize);

		cout << "#" << tc << " " << zeroCnt << " " << oneCnt << '\n';
	}
	return 0;
}