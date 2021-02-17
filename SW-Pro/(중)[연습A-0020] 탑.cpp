#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int arr[500001];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T = 0;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {

		int topCnt = 0;
		cin >> topCnt;

		int result = 0;

		for (int i = 1; i <= topCnt; i++) {
			long long input = 0;
			cin >> input;
			arr[i] = input % 1000000007;
		}

		for (int i = topCnt; i > 1; i--) {
			for (int j = i - 1; j > 0; j--) {

				if (arr[i] <= arr[j]) {
					// Modular ¿¬»ê
					// (a + b) mod n = (a mod n + b mod n) mod n
					result = (result + j) % 1000000007;
					break;
				}
			}
		}

		cout << "#" << tc << " " << result % 1000000007 << '\n';
	}
	return 0;
}