#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int arrSize, targetSum, ans;
int arr[10001];

void twoPointer() {
	int start = 0;
	int end = 0;
	int sum = 0;

	while (start <= end && end <= arrSize) {

		if (sum < targetSum) {
			sum = sum + arr[end++];
		}
		else if (targetSum < sum) {
			sum = sum - arr[start++];
		}
		else {
			ans++;
			sum = sum - arr[start++];

			if (end < start) {
				start--;
				sum = sum + arr[end++];
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> arrSize >> targetSum;
	memset(arr, 0, sizeof(arr));

	for (int i = 0; i < arrSize; i++) {
		cin >> arr[i];
	}

	twoPointer();

	cout << ans << '\n';

	return 0;
}