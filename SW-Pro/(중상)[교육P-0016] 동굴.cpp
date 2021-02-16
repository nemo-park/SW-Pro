#include <iostream>
#include <string>
#include <cstring>
#include <climits>
#include <algorithm>
#include <vector>
using namespace std;

pair<int, int> arr[200001];
int bar[500001];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc = 0;
	cin >> tc;

	for (int t = 1; t <= tc; t++) {

		int len, hgt;
		cin >> len >> hgt;

		memset(arr, 0, sizeof(arr));
		memset(bar, 0, sizeof(bar));

		for (int i = 1; i <= len; i++) {
			int bLen = 0;
			cin >> bLen;
			arr[i] = { i, bLen };
		}

		for (int i = 1; i <= len; i++) {

			// 홀수: 아래부터 자라나는 Barrier
			if (arr[i].first % 2 == 1) {
				// 높이 1부터 Barrier 자라남
				bar[1]++;
				
				// Barrier 의 높이 + 1 에서 - 처리
				bar[arr[i].second + 1]--;
			}
			else {
				// 짝수: 위에서 내려오는 Barrier
				bar[hgt - arr[i].second + 1]++;
			}
		}

		// 높이별 Barrier 누적합
		for (int i = 2; i <= hgt; i++) {
			bar[i] = bar[i] + bar[i - 1];
		}

		// sort(배열의 시작점, 종료점 + 1) : default 오름차순 정렬
		sort(bar + 1, bar + hgt + 1);

		int minVal = bar[1];
		int minCnt = 1;

		for (int i = 2; i <= hgt; i++) {
			if (bar[i] == minVal)	minCnt++;
			else break;
		}

		cout << "#" << t << " " << minVal << " " << minCnt << '\n';
	}

	return 0;
}