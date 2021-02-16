#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int arr[1000001];
int holeSize, cnt;
string ans;

void twoPointer() {

	int start = 0;
	int end = cnt - 1;

	while (start < end) {

		if (arr[start] + arr[end] == holeSize) {
			ans = "yes " + to_string(arr[start]) + " " + to_string(arr[end]);
			break;
		}
		else if (arr[start] + arr[end] > holeSize) {
			end--;
		}
		else {
			start++;
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc = 0;
	cin >> tc;

	for (int t = 1; t <= tc; t++) {

		cin >> holeSize;

		// cm > nm
		holeSize = holeSize * 10000000;

		cin >> cnt;

		memset(arr, 0, sizeof(arr));
		ans = "danger";

		for (int i = 0; i < cnt; i++) {
			cin >> arr[i];
		}

		// 오름차순 정렬
		sort(arr, arr + cnt);

		twoPointer();

		cout << "#" << t << " " << ans << '\n';
	}
	return 0;
}