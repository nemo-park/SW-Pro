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

			// Ȧ��: �Ʒ����� �ڶ󳪴� Barrier
			if (arr[i].first % 2 == 1) {
				// ���� 1���� Barrier �ڶ�
				bar[1]++;
				
				// Barrier �� ���� + 1 ���� - ó��
				bar[arr[i].second + 1]--;
			}
			else {
				// ¦��: ������ �������� Barrier
				bar[hgt - arr[i].second + 1]++;
			}
		}

		// ���̺� Barrier ������
		for (int i = 2; i <= hgt; i++) {
			bar[i] = bar[i] + bar[i - 1];
		}

		// sort(�迭�� ������, ������ + 1) : default �������� ����
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