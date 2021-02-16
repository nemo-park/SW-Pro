#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int N, M;
int arrN[100001];
int arrM[100001];

int binarySearch(int target) {
	int start = 0;
	int end = N - 1;

	while (start <= end) {
		int mid = (start + end) / 2;

		if (arrN[mid] == target) {
			return 1;
		}
		else if (arrN[mid] < target) {
			start = mid + 1;
		}
		else
		{
			end = mid - 1;
		}
	}

	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arrN[i];
	}

	sort(arrN, arrN + N);

	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> arrM[i];
	}

	for (int i = 0; i < M; i++) {
		cout << binarySearch(arrM[i]) << '\n';
	}

	return 0;
}