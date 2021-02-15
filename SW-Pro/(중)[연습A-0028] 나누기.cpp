#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int zeroCnt, oneCnt;
int arr[129][129];

bool fullScan(int x, int y, int size) {
	int chkVal = arr[x][y];

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (arr[x + i][y + j] != chkVal) return false;
		}
	}

	return true;
}



void chkCnt(int x, int y, int size) {
	if (fullScan(x, y, size)) {
		if (arr[x][y] == 0)	zeroCnt++;
		else oneCnt++;

		return;
	}

	size = size / 2;

	chkCnt(x, y, size);
	chkCnt(x + size, y, size);
	chkCnt(x, y + size, size);
	chkCnt(x + size, y + size, size);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc = 0;
	cin >> tc;

	for (int i = 0; i < tc; i++) {
		zeroCnt = 0;	oneCnt = 0;
		// 배열 초기화
		memset(arr, 0, sizeof(arr));

		int size = 0;
		cin >> size;

		for (int j = 1; j <= size; j++) {
			for (int k = 1; k <= size; k++) {
				cin >> arr[j][k];
			}
		}

		chkCnt(1, 1, size);
		cout << "#" << (i + 1) << " " << zeroCnt << " " << oneCnt << '\n';
	}
	return 0;
}