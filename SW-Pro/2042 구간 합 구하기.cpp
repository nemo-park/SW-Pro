#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

long long idxTree[4000001];

void update(int idx, long long diffVal) {

	while (idx > 0) {
		idxTree[idx] += diffVal;
		idx = idx / 2;
	}
}

long long findSum(long long s, long long e) {

	long long ans = 0;

	while (s <= e) {
		if (s % 2 == 1) ans += idxTree[s];
		if (e % 2 == 0) ans += idxTree[e];

		s = (s + 1) / 2;
		e = (e - 1) / 2;
	}
	return ans;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int inputCnt = 0;
	int modifyCnt = 0;
	int sumCnt = 0;
	cin >> inputCnt >> modifyCnt >> sumCnt;

	int leafSize = 1;
	while (leafSize < inputCnt) {
		// inputCnt 보다 큰 가장 작은 2의 제곱수
		leafSize *= 2;
	}

	for (int i = 0; i < inputCnt; i++) {
		cin >> idxTree[leafSize + i];
	}

	for (int i = leafSize - 1; i > 0; i--) {
		// 트리 채우기
		idxTree[i] = idxTree[i * 2] + idxTree[(i * 2) + 1];
	}

	for (int i = 0; i < modifyCnt + sumCnt; i++) {

		long long a, b, c;
		cin >> a >> b >> c;

		if (a == 1) {
			update(leafSize - 1 + b, c - idxTree[leafSize - 1 + b]);
		}
		else if (a == 2) {
			cout << findSum(leafSize - 1 + b, leafSize - 1 + c) << '\n';
		}
	}
	return 0;
}