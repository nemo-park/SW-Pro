#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#define MAX_N 100002
using namespace std;

int parent[MAX_N];

int findParent(int a) {
	if (a == parent[a]) return parent[a];
	return parent[a] = findParent(parent[a]);
}

void unionParent(int a, int b) {

	int aRoot = findParent(a);
	int bRoot = findParent(b);

	if (aRoot == bRoot) return;

	// 연속적인 무효화값을 하나의 Group 으로 묶음
	// 점수를 획득할 수 있는 Next idx 저장
	if (aRoot < bRoot) parent[aRoot] = bRoot;
	else parent[bRoot] = aRoot;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T = 0;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {

		int totCnt = 0;	int caseCnt = 0;
		cin >> totCnt >> caseCnt;

		// totCnt + 1 만큼 값이 있어야 하기 while 문에서 종료할 수 있음
		for (int i = 1; i <= totCnt + 1; i++) {
			parent[i] = i;
		}

		int result = 0;
		for (int i = 1; i <= caseCnt; i++) {
			for (int i = 1; i <= caseCnt; i++) {

			int start = 0;	int end = 0;
			cin >> start >> end;

			int cnt = 0;

			start = findParent(start);
			while (start <= end) {
			
				if (start == parent[start]) {
					cnt++;
					unionParent(start, start + 1);

					start = findParent(start);
				}
			}

			if (i % 2 == 1) result += cnt;
			else result -= cnt;
		}

		cout << "#" << tc << " " << result << '\n';

	}
	return 0;
}