#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#define MAX_SPEED 1000000001
using namespace std;

int totCnt, caseCnt, S, E;

struct node {
	int start;
	int end;
	int cost;
};

vector<node> v;
int parent[1001];

bool compare(node a, node b) {
	return a.cost < b.cost;
}

int findParent(int a) {
	if (parent[a] == a) return parent[a];
	return parent[a] = findParent(parent[a]);
}

void unionParent(int a, int b) {

	int aRoot = findParent(a);
	int bRoot = findParent(b);

	if (aRoot == bRoot) return;

	if (aRoot < bRoot) parent[bRoot] = aRoot;
	else parent[aRoot] = bRoot;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T = 0;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {

		cin >> totCnt >> caseCnt;

		int ans = MAX_SPEED;
		v.clear();

		for (int i = 0; i < caseCnt; i++) {
			int s = 0; int e = 0; int cost = 0;
			cin >> s >> e >> cost;
			v.push_back({ s, e, cost });
		}

		cin >> S >> E;

		sort(v.begin(), v.end(), compare);

		for (int i = 0; i < caseCnt; i++) {

			int minVal = v[i].cost;
			int maxVal = 0;

			// Parent 초기화
			for (int j = 1; j <= totCnt; j++) {
				parent[j] = j;
			}

			bool flag = false;
			for (int j = i; j < caseCnt; j++) {
				
				int start = v[j].start;
				int end = v[j].end;
				int cost = v[j].cost;

				maxVal = max(maxVal, cost);

				// 사이클이 발생해선 안됨
				if (findParent(start) != findParent(end)) {
					unionParent(start, end);
				}

				if (findParent(S) == findParent(E)) {
					flag = true;
					int temp = maxVal - minVal;
					ans = min(ans, temp);
					break;
				}
			}

			// 크루스칼을 만들수가 없다면, 다음 idx는 증가할 필요가 없음
			// 모수가 더 적어졌기 때문
			if (!flag) break;

		}

		cout << "#" << tc << " " << ans << '\n';
	}

	return 0;

}