#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int parent[1001];
int member[1001];

// Find Function : 인수로 넘긴 정점의 부모 정점을 알려줌
int getParent(int a) {

	// 조상은 부모가 자기 자신. 조상을 찾았을 때 return
	if (parent[a] == a) return a;

	// parent[x] = parent[parent[x]] = parent[parent[parent[x]]] 이런식! x의 조상이 리턴됨. 
	return parent[a] = getParent(parent[a]);

}

// Union Function : 부모가 같은 그룹으로 두 정점을 병합함
void unionParent(int a, int b) {

	int aRoot = getParent(a);
	int bRoot = getParent(b);

	// 루트가 같다면 이미 같은 트리
	if (aRoot == bRoot)	return;

	// 더 조상인 부모로 합치기 위해, 보통 더 작은 값을 가진 부모로 통합한다.
	if (aRoot < bRoot) {
		parent[bRoot] = aRoot;
		member[aRoot] += member[bRoot];
		member[bRoot] = 0;
	}
	else {
		parent[aRoot] = bRoot;
		member[bRoot] += member[aRoot];
		member[aRoot] = 0;
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T = 0;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {

		memset(parent, 0, sizeof(parent));
		memset(member, 0, sizeof(member));

		int pCnt = 0;	int caseCnt = 0;
		cin >> pCnt >> caseCnt;

		// Initialize
		for (int i = 1; i <= pCnt; i++) {
			parent[i] = i;
			member[i] = 1;
		}

		for (int i = 0; i < caseCnt; i++) {
			int a = 0; int b = 0;
			cin >> a >> b;
			unionParent(a, b);
		}

		int gCnt = 0;
		int maxCnt = 0;
		for (int i = 1; i <= pCnt; i++) {
			if (member[i] > 1) {
				gCnt++;
				maxCnt = max(maxCnt, member[i]);
			}
		}

		cout << "#" << tc << " " << gCnt << " " << maxCnt << '\n';
	}

	return 0;

}